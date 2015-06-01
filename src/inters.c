/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inters.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 12:10:21 by eruffieu          #+#    #+#             */
/*   Updated: 2015/06/01 17:14:18 by aleung-c         ###   ########.fr       */
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
		res = touch2(tmp->obj, *current_vec, origin);
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

void	inters2(int reflect, t_point *cam_ori, t_pix *cur_pix
	, t_vec *current_vec)
{
	t_vec		tmp;

	if (reflect != -1 && cur_pix->cur_obj->reflection > 0.0)
	{
		pointcpy(cam_ori, cur_pix->inter);
		*current_vec = normalize(vec_sum(get_normale(cur_pix, *cam_ori)
			, vec_sum(*current_vec, get_normale(cur_pix, *cam_ori))));
	}
	else if (reflect != -1 && cur_pix->cur_obj->refraction > 0.0
		&& cur_pix->cur_obj->transparence > 0.0)
	{
		pointcpy(cam_ori, cur_pix->inter);
		tmp = get_normale(cur_pix, *cam_ori);
		current_vec->x += -tmp.x / cur_pix->cur_obj->refraction;
		current_vec->y += -tmp.y / cur_pix->cur_obj->refraction;
		current_vec->z += -tmp.z / cur_pix->cur_obj->refraction;
	}
	else if (reflect != -1 && cur_pix->cur_obj->transparence > 0.0)
		pointcpy(cam_ori, cur_pix->inter);
}

int		inters3(double dist_ref[2], t_point cam_ori, t_pix *pix
	, t_vec current_vec)
{
	if (dist_ref[0] == -1.0 && pix->first_obj != NULL)
		return (1);
	if (dist_ref[0] == -1.0)
	{
		pix->dist = -1.0;
		pix->cur_obj = NULL;
		return (1);
	}
	else
	{
		pix->inter2 = translate(cam_ori, vec_coef(current_vec, dist_ref[0]));
		pix->inter = do_rotate(pix->cur_obj->rot
			, pix->inter2);
		pix->dist = dist_ref[0];
		if (dist_ref[1] == -1 && (pix->cur_obj->reflection > 0.0
			|| pix->cur_obj->transparence > 0.0))
			pix->first_obj = pix->cur_obj;
	}
	if (!(pix->cur_obj->reflection > 0.0
		|| pix->cur_obj->transparence > 0.0))
		return (1);
	return (0);
}

void	inters(t_libx *mlx, int pix, int pix_x, int pix_y)
{
	double		dist_ref[2];
	t_point		cam_ori;
	t_vec		current_vec;
	int			nb_reflex;

	dist_ref[1] = -1;
	nb_reflex = 0;
	cam_ori = mlx->cam->coord;
	current_vec = mlx->pix[pix]->pos_pix_vec;
	mlx->pix[pix]->pix_x = pix_x;
	mlx->pix[pix]->pix_y = pix_y;
	mlx->pix[pix]->first_obj = NULL;
	while ((dist_ref[1] == 1 || dist_ref[1] == -1) && nb_reflex < 10)
	{
		nb_reflex++;
		inters2(dist_ref[1], &cam_ori, mlx->pix[pix], &current_vec);
		dist_ref[0] = touch_in(&current_vec, cam_ori, mlx, pix);
		if (inters3(dist_ref, cam_ori, mlx->pix[pix], current_vec))
			return ;
		dist_ref[1] = 1;
	}
}
