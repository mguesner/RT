/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 10:03:28 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/13 15:08:41 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <vecteur.h>
#include <stdio.h>

static void		set_color(t_libx *m, t_pix *pix)
{
	int		pos;

	pos = ((pix->pix_y) * (m->size_line) + pix->pix_x * (m->bpp / 8));
	m->data[pos] = pix->cur_obj->color.b;
	m->data[pos + 1] = pix->cur_obj->color.g;
	m->data[pos + 2] = pix->cur_obj->color.r;
}

static t_point	intersection_point(double r, t_vec a)
{
	t_point		ret;

	ret.x = r * a.x;
	ret.y = r * a.y;
	ret.z = r * a.z;
	return (ret);
}

static int		shadow(t_obj *obj, t_obj_list *list, t_point inter)
{
	double		res;
	t_obj_list	*tmp;
	t_vec		vec;
	double		norm;

	tmp = list;
	vec = make_vec(obj->coord, inter);
	norm = norme(vec);
	vec = normalize(vec);
	while (tmp)
	{
		res = touch(tmp->obj, &vec, &inter);
		if (tmp->obj != obj && res > 0.001 && res < norm)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void			calc_lum(t_libx *mlx, t_pix *vec_dir)
{
	t_point		inter_point;
	t_obj_list	*tmp;

	if (vec_dir->cur_obj == NULL)
		return ;
	inter_point = intersection_point(vec_dir->dist, vec_dir->pos_pix_vec);
	tmp = mlx->obj->begin;
	while (tmp)
	{
		if (tmp->obj->type == LIGHT)
		{
			if (!shadow(tmp->obj, mlx->obj->begin, inter_point))
				set_color(mlx, vec_dir);
		}
		tmp = tmp->next;
	}
}
