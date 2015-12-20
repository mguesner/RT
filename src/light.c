/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 10:03:28 by eruffieu          #+#    #+#             */
/*   Updated: 2015/06/02 13:08:41 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
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
	coef = m->cam->ambient / 100.;
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

static int			shadow(t_obj *light, t_obj_list *tmp
	, t_point inter, t_pix *vec_dir)
{
	double		d[3];
	t_vec		vec[2];

	vec[0] = make_vec(light->coord, vec_dir->inter2);
	vec[1] = make_vec(light->coord, inter);
	d[1] = norme(vec[0]);
	vec[0] = normalize(vec[0]);
	d[0] = -1.0;
	while (tmp)
	{
		if (tmp->obj == vec_dir->cur_obj)
			d[2] = touch2(tmp->obj, vec[1], inter);
		else
			d[2] = touch(tmp->obj, &(vec[0]), &vec_dir->inter2);
		if (d[2] > 0.001 && d[2] < d[1] && ((d[0] == -1) ||
			((tmp->obj->transparence < vec_dir->shadow_obj->transparence))))
			shadow_subfunc(&vec_dir, d, tmp);
		tmp = tmp->next;
	}
	if (d[0] != -1)
		return (1);
	vec_dir->shadow_obj = NULL;
	return (0);
}

void				calc_lum2(t_libx *mlx, t_pix *vec_d)
{
	t_obj_list	*lights;
	int			light_dist;

	lights = mlx->spots.begin;
	while (lights)
	{
		light_dist = 0;
		if (vec_d->cur_obj->reflection <= 0.0)
			light_dist = shadow(lights->obj, mlx->obj.begin
				, vec_d->inter, vec_d);
		if (light_dist)
			set_color_shad(mlx, vec_d);
		if (!light_dist || (vec_d->shadow_obj
			&& vec_d->shadow_obj->transparence != 0.0))
		{
			vec_d->coef = mlx->cam->ambient / 100.;
			set_color_light(lights->obj, vec_d, vec_d->inter, mlx->spots.size);
			if (!vec_d->is_in_shadow && vec_d->cur_obj->specular)
				apply_specular(mlx, vec_d);
		}
		lights = lights->next;
	}
	if (vec_d->is_in_shadow || !vec_d->cur_obj->specular)
		set_color(mlx, vec_d, 0);
	else
		set_color(mlx, vec_d, 1);
}

void				calc_lum(t_libx *mlx, t_pix *vec_dir)
{
	if (vec_dir->cur_obj == NULL)
		return ;
	if (vec_dir->cur_obj->texture.exist == 1)
		texture_func(vec_dir);
	else
	{
		if (vec_dir->first_obj != NULL && vec_dir->first_obj
			== vec_dir->cur_obj && vec_dir->first_obj->reflection > 0.0)
			set_finish_reflection_one(vec_dir);
		else if (vec_dir->first_obj != NULL && vec_dir->first_obj
			== vec_dir->cur_obj && vec_dir->first_obj->transparence > 0.0)
			set_finish_transparence_one(vec_dir);
		else if (vec_dir->first_obj != NULL
			&& vec_dir->first_obj->transparence > 0.0)
			set_finish_transparence(vec_dir);
		else if (vec_dir->first_obj != NULL)
			set_finish_reflection(vec_dir);
		else
			set_original(vec_dir);
	}
	vec_dir->is_in_shadow = 0;
	calc_lum2(mlx, vec_dir);
}
