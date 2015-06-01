/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 10:03:28 by eruffieu          #+#    #+#             */
/*   Updated: 2015/06/01 11:25:38 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>
#include <matrice.h>

void				set_color(t_libx *m, t_pix *pix, int spec_or_not)
{
	int		pos;

	pos = ((pix->pix_y) * (m->size_line) + pix->pix_x * (m->bpp / 8));
	if (!spec_or_not)
	{
		m->data[pos] = pix->color->b;
		m->data[pos + 1] = pix->color->g;
		m->data[pos + 2] = pix->color->r;
	}
	else
	{
		m->data[pos] = pix->color_specular->b;
		m->data[pos + 1] = pix->color_specular->g;
		m->data[pos + 2] = pix->color_specular->r;
	}
}

static void			set_color_shad(t_libx *m, t_pix *pix)
{
	int		pos;
	int		white;
	double	coef;

	white = 255 * 3;
	pix->is_in_shadow = 1;
	coef = 0.2;
	coef *= m->spots.size;
	coef += pix->shadow_obj->transparence;
	if (coef > 0.9)
		coef = 0.9;
	if (pix->shadow_obj->transparence == 1.0)
		coef = 1.0;
	pos = ((pix->pix_y) * (m->size_line) + pix->pix_x * (m->bpp / 8));
	pix->color->b = pix->color->b * coef;
	pix->color->g = pix->color->g * coef;
	pix->color->r = pix->color->r * coef;
}

static int	shadow(t_obj *light, t_obj_list *tmp
	, t_point inter, t_pix *vec_dir)
{
	double		res;
	t_vec		vec;
	t_vec		vec2;
	double		dist_to_light;
	double		dist;

	vec = make_vec(light->coord, vec_dir->inter2);
	vec2 = make_vec(light->coord, inter);
	dist_to_light = norme(vec);
	vec = normalize(vec);
	dist = -1.0;
	while (tmp)
	{
		if (tmp->obj == vec_dir->cur_obj)
		{
			res = touch2(tmp->obj, vec2, inter);
			vec_dir->debug = 1;
		}
		else
		{
			res = touch(tmp->obj, &vec, &vec_dir->inter2);
			vec_dir->debug = 0;
		}
		if (res > 0.001 && res < dist_to_light && ((dist == -1) || ((tmp->obj->transparence < vec_dir->shadow_obj->transparence))))
		{
			vec_dir->in_shadow = tmp->obj;
			vec_dir->shadow_dist = res;
			vec_dir->light_dist = dist_to_light;
			vec_dir->shadow_obj = tmp->obj;
			dist = res;
		}
		tmp = tmp->next;
	}
	if (dist != -1)
		return (1);
	vec_dir->shadow_obj = NULL;
	return (0);
}

void				calc_lum2(t_libx *mlx, t_pix *vec_dir)
{
	t_obj_list	*lights;
	int	light_dist;

	lights = mlx->spots.begin;
	while (lights)
	{
		light_dist = 0;
		if (vec_dir->cur_obj->reflection <= 0.0)
			light_dist = shadow(lights->obj, mlx->obj.begin
				, vec_dir->inter, vec_dir);
		if (light_dist)
			set_color_shad(mlx, vec_dir);
		if (!light_dist || (vec_dir->shadow_obj && vec_dir->shadow_obj->transparence != 0.0))
		{
			set_color_light(lights->obj, vec_dir
				, vec_dir->inter, mlx->spots.size);
			if (!vec_dir->is_in_shadow && vec_dir->cur_obj->specular)
				apply_specular(mlx, vec_dir);
		}
		lights = lights->next;
	}
	if (vec_dir->is_in_shadow || !vec_dir->cur_obj->specular)
		set_color(mlx, vec_dir, 0);
	else
		set_color(mlx, vec_dir, 1);
}

void				calc_lum(t_libx *mlx, t_pix *vec_dir)
{
	if (vec_dir->cur_obj == NULL)
		return ;
	if (vec_dir->cur_obj->texture.exist == 1)
		texture_func(vec_dir);
	else
	{
		if (vec_dir->first_obj != NULL && vec_dir->first_obj == vec_dir->cur_obj && vec_dir->first_obj->reflection > 0.0)
		{
			vec_dir->color->b = vec_dir->cur_obj->color.b *  (1.0 - vec_dir->first_obj->reflection);
			if (vec_dir->color->b > 255)
				vec_dir->color->b = 255;
			else if (vec_dir->color->b < 0)
				vec_dir->color->b = 0;
			vec_dir->color->g =  vec_dir->cur_obj->color.g * (1.0 - vec_dir->first_obj->reflection);
			if (vec_dir->color->g > 255)
				vec_dir->color->g = 255;
			else if (vec_dir->color->g < 0)
				vec_dir->color->g = 0;
			vec_dir->color->r =  vec_dir->cur_obj->color.r * (1.0 - vec_dir->first_obj->reflection);
			if (vec_dir->color->r > 255)
				vec_dir->color->r = 255;
			else if (vec_dir->color->r < 0)
				vec_dir->color->r = 0;
		}
		else if (vec_dir->first_obj != NULL && vec_dir->first_obj == vec_dir->cur_obj && vec_dir->first_obj->transparence > 0.0)
		{
			vec_dir->color->b = vec_dir->cur_obj->color.b *  (1.0 - vec_dir->first_obj->transparence);
			if (vec_dir->color->b > 255)
				vec_dir->color->b = 255;
			else if (vec_dir->color->b < 0)
				vec_dir->color->b = 0;
			vec_dir->color->g =  vec_dir->cur_obj->color.g * (1.0 - vec_dir->first_obj->transparence);
			if (vec_dir->color->g > 255)
				vec_dir->color->g = 255;
			else if (vec_dir->color->g < 0)
				vec_dir->color->g = 0;
			vec_dir->color->r =  vec_dir->cur_obj->color.r * (1.0 - vec_dir->first_obj->transparence);
			if (vec_dir->color->r > 255)
				vec_dir->color->r = 255;
			else if (vec_dir->color->r < 0)
				vec_dir->color->r = 0;
		}
		else if (vec_dir->first_obj != NULL && vec_dir->first_obj->transparence > 0.0)
		{
			vec_dir->color->b = vec_dir->cur_obj->color.b * (vec_dir->first_obj->transparence) + vec_dir->first_obj->color.b * (1.0 - vec_dir->first_obj->transparence);
			if (vec_dir->color->b > 255)
				vec_dir->color->b = 255;
			else if (vec_dir->color->b < 0)
				vec_dir->color->b = 0;
			vec_dir->color->g = vec_dir->cur_obj->color.g * (vec_dir->first_obj->transparence) + vec_dir->first_obj->color.g * (1.0 - vec_dir->first_obj->transparence);
			if (vec_dir->color->g > 255)
				vec_dir->color->g = 255;
			else if (vec_dir->color->g < 0)
				vec_dir->color->g = 0;
			vec_dir->color->r = vec_dir->cur_obj->color.r * (vec_dir->first_obj->transparence) + vec_dir->first_obj->color.r * (1.0 - vec_dir->first_obj->transparence);
			if (vec_dir->color->r > 255)
				vec_dir->color->r = 255;
			else if (vec_dir->color->r < 0)
				vec_dir->color->r = 0;
		}
		else if (vec_dir->first_obj != NULL)
		{
			vec_dir->color->b = vec_dir->cur_obj->color.b + vec_dir->first_obj->color.b * (1.0 - vec_dir->first_obj->reflection);
			if (vec_dir->color->b > 255)
				vec_dir->color->b = 255;
			else if (vec_dir->color->b < 0)
				vec_dir->color->b = 0;
			vec_dir->color->g = vec_dir->cur_obj->color.g + vec_dir->first_obj->color.g * (1.0 - vec_dir->first_obj->reflection);
			if (vec_dir->color->g > 255)
				vec_dir->color->g = 255;
			else if (vec_dir->color->g < 0)
				vec_dir->color->g = 0;
			vec_dir->color->r = vec_dir->cur_obj->color.r + vec_dir->first_obj->color.r * (1.0 - vec_dir->first_obj->reflection);
			if (vec_dir->color->r > 255)
				vec_dir->color->r = 255;
			else if (vec_dir->color->r < 0)
				vec_dir->color->r = 0;
		}
		else
		{
			vec_dir->color->b = vec_dir->cur_obj->color.b;
			vec_dir->color->g = vec_dir->cur_obj->color.g;
			vec_dir->color->r = vec_dir->cur_obj->color.r;
		}
	}
	vec_dir->is_in_shadow = 0;
	calc_lum2(mlx, vec_dir);
}
