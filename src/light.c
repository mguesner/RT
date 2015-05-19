/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 10:03:28 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/19 16:32:44 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>
#include <matrice.h>

void		set_color(t_libx *m, t_pix *pix)
{
	int		pos;

	pos = ((pix->pix_y) * (m->size_line) + pix->pix_x * (m->bpp / 8));
	m->data[pos] = pix->color->b;
	m->data[pos + 1] = pix->color->g;
	m->data[pos + 2] = pix->color->r;
}

static void	set_color_shad(t_pix *pix)
{
	pix->color->b = pix->color->b * LIGHT_IN_SHADOW;
	pix->color->r = pix->color->r * LIGHT_IN_SHADOW;
	pix->color->g = pix->color->g * LIGHT_IN_SHADOW;
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

	t_point		inter_point;
	t_obj_list	*tmp;
	t_obj_list	*light_dist;

	if (vec_dir->cur_obj == NULL)
		return ;
	inter_point = translate(mlx->cam->coord,
		vec_coef(vec_dir->pos_pix_vec, vec_dir->dist));
	tmp = mlx->spots.begin;
	while (tmp)
	{
		light_dist = shadow(tmp->obj, mlx->obj.begin, inter_point, vec_dir);
		if (vec_dir->cur_obj->type == SPHERE && vec_dir->cur_obj->texture.exist == 1)
			texture_func(vec_dir);
		else
		{
			vec_dir->color->b = vec_dir->cur_obj->color.b;
			vec_dir->color->g = vec_dir->cur_obj->color.g;
			vec_dir->color->r = vec_dir->cur_obj->color.r;
		}
		if (light_dist)
			// ;
			set_color_shad(vec_dir);
		else
			set_color_light(tmp->obj, vec_dir, vec_dir->inter);
		set_color(mlx, vec_dir);
		tmp = tmp->next;
	}
}
