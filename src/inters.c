/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inters.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 12:10:21 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/25 14:36:36 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>
#include <matrice.h>

double	inters(t_libx *mlx, int pix, int pix_x, int pix_y)
{
	t_obj_list	*tmp;
	double		dist;
	double		res;
	t_point		cam_ori;
	t_vec		current_vec;

	cam_ori = mlx->cam->coord;
	current_vec = mlx->pix[pix]->pos_pix_vec;
	tmp = mlx->obj.begin;
	dist = -1.0;
	mlx->pix[pix]->pix_x = pix_x;
	mlx->pix[pix]->pix_y = pix_y;
	while (tmp)
	{
		res = touch(tmp->obj, &current_vec, &cam_ori);
		if ((res) > 0.0001)
		{
			if (res < dist || dist == -1)
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
	else
		mlx->pix[pix]->inter = do_rotate(mlx->pix[pix]->cur_obj->rot, translate(cam_ori,
					vec_coef(current_vec, dist)));
	return (dist);
}
