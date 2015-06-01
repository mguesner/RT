/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inters.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 12:10:21 by eruffieu          #+#    #+#             */
/*   Updated: 2015/06/01 13:36:20 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include <stdio.h>
#include <matrice.h>


float	touch_in(t_vec *current_vec, t_point origin, t_libx *mlx, int pix)
{
	double		dist;
	double		res;
	t_obj_list	*tmp;

	dist = -1.0;
	tmp = mlx->obj.begin;
	while (tmp)
	{
		res = touch(tmp->obj, current_vec, &origin);
		if ((res) > 0.001)
		{
			if (res < dist || dist == -1)
			{
				mlx->pix[pix]->cur_obj = tmp->obj;
				dist = res;
			}
		}
		tmp = tmp->next;
	}
	return (dist);
}

void	inters(t_libx *mlx, int pix, int pix_x, int pix_y)
{
	double		dist;
	t_point		cam_ori;
	t_vec		current_vec;
	int			reflect;
	int			nb_reflex;
	t_pix		*cur_pix;
	t_vec		tmp;

	reflect = -1;
	nb_reflex = 0;
	cur_pix = mlx->pix[pix];
	cam_ori = mlx->cam->coord;
	current_vec = cur_pix->pos_pix_vec;
	dist = -1.0;
	cur_pix->pix_x = pix_x;
	cur_pix->pix_y = pix_y;
	cur_pix->first_obj = NULL;
	while((reflect == 1 || reflect == -1) && nb_reflex < 10)
	{
		nb_reflex++;
		if (reflect != -1 && cur_pix->cur_obj->reflection > 0.0)
		{
			cam_ori.x = cur_pix->inter.x;
			cam_ori.y = cur_pix->inter.y;
			cam_ori.z = cur_pix->inter.z;
			current_vec = vec_sum(current_vec, get_normale(cur_pix, cam_ori));
			current_vec = normalize(vec_sum(get_normale(cur_pix, cam_ori), current_vec));
		}
		else if (reflect != -1 && cur_pix->cur_obj->refraction > 0.0 && cur_pix->cur_obj->transparence > 0.0)
		{
			cam_ori.x = cur_pix->inter.x;
			cam_ori.y = cur_pix->inter.y;
			cam_ori.z = cur_pix->inter.z;
			tmp = get_normale(cur_pix, cam_ori);
			current_vec.x += -tmp.x / cur_pix->cur_obj->refraction;
			current_vec.y += -tmp.y / cur_pix->cur_obj->refraction;
			current_vec.z += -tmp.z / cur_pix->cur_obj->refraction;
		}
		else if (reflect != -1 && cur_pix->cur_obj->transparence > 0.0)
		{
			cam_ori.x = cur_pix->inter.x;
			cam_ori.y = cur_pix->inter.y;
			cam_ori.z = cur_pix->inter.z;
		}
		dist = touch_in(&current_vec, cam_ori, mlx, pix);
		if (dist == -1.0)
		{
			if (cur_pix->first_obj != NULL)
			{
				cur_pix->dist = -1.0;
				cur_pix->cur_obj = NULL;
			}
			return ;
		}
		else
		{
			cur_pix->inter2 = translate(cam_ori,
				vec_coef(current_vec, dist));
			cur_pix->inter = do_rotate(cur_pix->cur_obj->rot, cur_pix->inter2);
			cur_pix->dist = dist;
			if (reflect == -1 && (cur_pix->cur_obj->reflection > 0.0 || cur_pix->cur_obj->transparence > 0.0))
				cur_pix->first_obj = cur_pix->cur_obj;
		}
		if (dist != -1.0 && (cur_pix->cur_obj->reflection > 0.0 || cur_pix->cur_obj->transparence > 0.0))
			reflect = 1;
		else
			return ;
	}
	return ;
}
