/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 10:03:28 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/25 15:13:35 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>
#include <matrice.h>

void		set_color(t_libx *m, t_pix *pix, int spec_or_not)
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

static void	set_color_shad(t_libx *m, t_pix *pix)
{
	int		pos;
	int		white;
	double	coef;

	white = 255 * 3;
	pix->is_in_shadow = 1;
	coef = 0.2 - (double)((pix->cur_obj->color.b + pix->cur_obj->color.g + pix->cur_obj->color.r) / white);
	coef *=  m->spots.size;
	if (coef > 0.9)
		coef = 0.9;
	pos = ((pix->pix_y) * (m->size_line) + pix->pix_x * (m->bpp / 8));
	pix->color->b = pix->color->b * coef;
	pix->color->g = pix->color->g * coef;
	pix->color->r = pix->color->r * coef;
}

static t_obj_list	*shadow(t_obj *light, t_obj_list *tmp, t_point inter, t_pix *vec_dir)
{
	double		res;
	t_vec		vec;
	double		dist_to_light;

	vec = make_vec(light->coord, inter);
	dist_to_light = norme(vec);
	vec = normalize(vec);
	while (tmp)
	{
		res = touch(tmp->obj, &vec, &inter);
		if (res > 0.001 && res < dist_to_light)
		{
			vec_dir->in_shadow = tmp->obj;
			vec_dir->shadow_dist = res;
			vec_dir->light_dist = dist_to_light;
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

void			calc_lum(t_libx *mlx, t_pix *vec_dir)
{
	t_obj_list	*lights;
	t_obj_list	*light_dist;

	if (vec_dir->cur_obj == NULL)
		return ;
	if (vec_dir->cur_obj->type == SPHERE && vec_dir->cur_obj->texture.exist == 1)
			texture_func(vec_dir);
	else
	{
		vec_dir->color->b = vec_dir->cur_obj->color.b;
		vec_dir->color->g = vec_dir->cur_obj->color.g;
		vec_dir->color->r = vec_dir->cur_obj->color.r;
	}
	lights = mlx->spots.begin;
	vec_dir->is_in_shadow = 0;
	while (lights)
	{
		light_dist = shadow(lights->obj, mlx->obj.begin, vec_dir->inter, vec_dir);
		if (light_dist)
			set_color_shad(mlx, vec_dir);
		else
		{
			set_color_light(lights->obj, vec_dir, vec_dir->inter, mlx->spots.size);
			if (!vec_dir->is_in_shadow)
				apply_specular(mlx, vec_dir);
		}
		lights = lights->next;
	}
	if (vec_dir->is_in_shadow)
		set_color(mlx, vec_dir, 0);
	else
		set_color(mlx, vec_dir, 1);
}
