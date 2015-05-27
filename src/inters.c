/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inters.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 12:10:21 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/27 14:20:34 by eruffieu         ###   ########.fr       */
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
		if ((res) > 0.0001)
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

void	init_next_ray_reflect(t_vec *vec, t_point *p, t_pix *pix)
{
	p->x = pix->inter.x;
	p->y = pix->inter.y;
	p->z = pix->inter.z;
	*vec = vec_sum(*vec, get_normale(pix, *p));
	*vec = normalize(vec_sum(get_normale(pix, *p), *vec));
}

void	init_next_ray_refract(t_vec *vec, t_point *p, t_pix *pix)
{
	t_vec	tmp;
	double	angle;

	p->x = pix->inter.x;
	p->y = pix->inter.y;
	p->z = pix->inter.z;
	tmp = get_normale(pix, *p);
	angle = acos(scalar(tmp, *vec));
	angle = asin((N1 / pix->cur_obj->refraction) * sin(angle));
	*vec = vec_coef(vec_coef(tmp, -1.0), (cos(angle)));
}

void	set_all_null(t_pix *pix, int *reflect)
{
	pix->dist = -1.0;
	pix->cur_obj = NULL;
	pix->first_obj = NULL;
	*reflect = 0;
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
	while((reflect == 1 || reflect == -1) && nb_reflex < 15)
	{
		nb_reflex++;
		if (reflect != -1 && mlx->pix[pix]->cur_obj->reflection > 0.0)
			init_next_ray_reflect(&current_vec, &cam_ori, mlx->pix[pix]);
		else if (reflect != -1 && mlx->pix[pix]->cur_obj->refraction > 0.0)
			init_next_ray_refract(&current_vec, &cam_ori, mlx->pix[pix]);
		dist = touch_in(&current_vec, cam_ori, mlx, pix);
		if (dist == -1.0 && reflect != -1)
			return ;
		if (dist == -1.0)
			set_all_null(mlx->pix[pix], &reflect);
		else
		{
			mlx->pix[pix]->inter = do_rotate(mlx->pix[pix]->cur_obj->rot, translate(cam_ori,
				vec_coef(current_vec, dist)));
			mlx->pix[pix]->dist = dist;
			if (reflect == -1 && (mlx->pix[pix]->cur_obj->reflection > 0.0 || mlx->pix[pix]->cur_obj->refraction > 0.0))
				mlx->pix[pix]->first_obj = mlx->pix[pix]->cur_obj;
		}
		if (mlx->pix[pix]->cur_obj->reflection > 0.0)
			reflect = 1;
		else
			reflect = 0;
	}
	return ;
}
