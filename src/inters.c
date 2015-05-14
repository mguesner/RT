/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inters.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 12:10:21 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/14 15:01:14 by bsourd-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>

double	inters(t_libx *mlx, int pix, int pix_x, int pix_y)
{
	t_obj_list	*tmp;
	double		dist;
	double		res;

	tmp = mlx->obj.begin;
	dist = -1.0;
	mlx->pix[pix]->pix_x = pix_x;
	mlx->pix[pix]->pix_y = pix_y;
	while (tmp)
	{
		// printf("%f ,%f, %f : obj\n", tmp->obj->coord.x, tmp->obj->coord.y, tmp->obj->coord.z);
		// printf("%f ,%f, %f : vec\n", mlx->pix[pix]->pos_pix_vec.x, mlx->pix[pix]->pos_pix_vec.y, mlx->pix[pix]->pos_pix_vec.z);
		// printf("%f ,%f, %f : cam\n", mlx->cam->coord.x, mlx->cam->coord.y, mlx->cam->coord.z);
		res = touch(tmp->obj, &(mlx->pix[pix]->pos_pix_vec), &(mlx->cam->coord));
		if ((res) > 0.0001)
		{
			if (dist == -1.0)
			{
				mlx->pix[pix]->cur_obj = tmp->obj;
				dist = res;
				mlx->pix[pix]->color->a = 0;
				mlx->pix[pix]->color->b = 0;
				mlx->pix[pix]->color->g = 0;
				mlx->pix[pix]->color->r = 0;
			}
			else if (res < dist)
			{
				mlx->pix[pix]->cur_obj = tmp->obj;
				dist = res;
				mlx->pix[pix]->color->a = 0;
				mlx->pix[pix]->color->b = 0;
				mlx->pix[pix]->color->g = 0;
				mlx->pix[pix]->color->r = 0;
			}
		}
		tmp = tmp->next;
	}
	if (dist == -1.0)
		mlx->pix[pix]->cur_obj = NULL;
	return (dist);
}
