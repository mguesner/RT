/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inters.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 12:10:21 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/13 14:36:15 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>

double	inters(t_libx *mlx, int pix, int pix_x, int pix_y)
{
	t_obj_list	*tmp;
	double		dist;
	double		res;

	tmp = mlx->obj->begin;
	dist = -1.0;
	mlx->pix[pix]->pix_x = pix_x;
	mlx->pix[pix]->pix_y = pix_y;
	while (tmp)
	{
		if ((res = touch(tmp->obj, &mlx->pix[pix]->pos_pix_vec,
			&mlx->cam->coord) > 0.0001))
		{
			if (dist == -1.0)
			{
				mlx->pix[pix]->cur_obj = tmp->obj;
				dist = res;
			}
			else if (res < dist)
			{
				mlx->pix[pix]->cur_obj = tmp->obj;
				dist = res;
			}
		}
		tmp = tmp->next;
	}
	if (dist == -1.0)
		mlx->pix[pix]->cur_obj = NULL;
	return (dist);
}
