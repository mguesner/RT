/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 10:03:28 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/14 15:00:57 by bsourd-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>

static void		set_color(t_libx *m, t_pix *pix)
{
	int		pos;

		pos = ((pix->pix_y) * (m->size_line) + pix->pix_x * (m->bpp / 8));
		m->data[pos] = pix->color->b;
		m->data[pos + 1] = pix->color->g;
		m->data[pos + 2] = pix->color->r;
}

static double	shadow(t_obj *obj, t_obj_list *tmp, t_point inter)
{
	double		res;
	t_vec		vec;
	double		norm;

	vec = make_vec(obj->coord, inter);
	norm = norme(vec);
	vec = normalize(vec);
	while (tmp)
	{
		res = touch(tmp->obj, &vec, &inter);
		if (res > 0.001 && res < norm)
			return (res);
		tmp = tmp->next;
	}
	return (0);
}

void			calc_lum(t_libx *mlx, t_pix *vec_dir)
{
	t_point		inter_point;
	t_obj_list	*tmp;
	double		light_dist;

	if (vec_dir->cur_obj == NULL)
		return ;
	inter_point = translate(mlx->cam->coord,
							vec_coef(vec_dir->pos_pix_vec, vec_dir->dist));
	tmp = mlx->spots.begin;
	while (tmp)
	{
		if (tmp->obj->type == LIGHT)
		{
			light_dist = shadow(tmp->obj, mlx->obj->begin, inter_point);
			if (!light_dist)
			{
				set_color_light(tmp->obj, vec_dir, inter_point);
				set_color(mlx, vec_dir);
			}
		}
		tmp = tmp->next;
	}
}
