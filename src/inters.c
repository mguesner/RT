/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inters.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 12:10:21 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/26 15:47:36 by eruffieu         ###   ########.fr       */
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

	reflect = -1;
	nb_reflex = 0;
	cam_ori = mlx->cam->coord;
	current_vec = mlx->pix[pix]->pos_pix_vec;
	dist = -1.0;
	mlx->pix[pix]->pix_x = pix_x;
	mlx->pix[pix]->pix_y = pix_y;
	mlx->pix[pix]->first_obj = NULL;
	while((reflect == 1 || reflect == -1) && nb_reflex < 10)
	{
		nb_reflex++;
		if (reflect != -1)
		{
			cam_ori.x = mlx->pix[pix]->inter.x;
			cam_ori.y = mlx->pix[pix]->inter.y;
			cam_ori.z = mlx->pix[pix]->inter.z;
			current_vec = vec_sum(current_vec, get_normale(mlx->pix[pix], cam_ori));
			current_vec = normalize(vec_sum(get_normale(mlx->pix[pix], cam_ori), current_vec));
		}
		dist = touch_in(&current_vec, cam_ori, mlx, pix);
		if (dist == -1.0 && reflect != -1)
			return ;
		if (dist == -1.0)
		{
			mlx->pix[pix]->dist = -1.0;
			mlx->pix[pix]->cur_obj = NULL;
			mlx->pix[pix]->first_obj = NULL;
		}
		else
		{
			mlx->pix[pix]->inter = do_rotate(mlx->pix[pix]->cur_obj->rot, translate(cam_ori,
				vec_coef(current_vec, dist)));
			mlx->pix[pix]->dist = dist;
			if (reflect == -1 && mlx->pix[pix]->cur_obj->reflection > 0.0)
				mlx->pix[pix]->first_obj = mlx->pix[pix]->cur_obj;

		}
		if (dist == -1.0)
			reflect = 0;
		else if (mlx->pix[pix]->cur_obj->reflection > 0.0)
			reflect = 1;
		else
			reflect = 0;
	}
	return ;
}
