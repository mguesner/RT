/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 10:03:28 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/19 14:06:08 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>
#include <matrice.h>

static void		set_color(t_libx *m, t_pix *pix)
{
	int		pos;

		pos = ((pix->pix_y) * (m->size_line) + pix->pix_x * (m->bpp / 8));
		m->data[pos] = pix->color->b;
		m->data[pos + 1] = pix->color->g;
		m->data[pos + 2] = pix->color->r;
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
		if (!light_dist)
		{
			// printf("inter : (%f, %f, %f) ->", inter_point.x, inter_point.y, inter_point.z);
			// inter_point = do_rotate(vec_dir->cur_obj->rot, inter_point);
			// printf(" (%f, %f, %f)", inter_point.x, inter_point.y, inter_point.z);
			// printf("\n(%f, %f, %f)\n(%f, %f, %f)\n(%f, %f, %f)\n"
			// 	, vec_dir->cur_obj->rot[0][0], vec_dir->cur_obj->rot[0][1], vec_dir->cur_obj->rot[0][2]
			// 	, vec_dir->cur_obj->rot[1][0], vec_dir->cur_obj->rot[1][1], vec_dir->cur_obj->rot[1][2]
			// 	, vec_dir->cur_obj->rot[2][0], vec_dir->cur_obj->rot[2][1], vec_dir->cur_obj->rot[2][2]);
			set_color_light(tmp->obj, vec_dir, vec_dir->inter);
			set_color(mlx, vec_dir);
		}
		tmp = tmp->next;
	}
}
