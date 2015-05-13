/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inters.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 12:10:21 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/13 12:16:58 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

double	inters(t_libx *mlx, int pix, int pix_x, int pix_y)
{
	t_obj_list	*tmp;
	double		dist;
	double		res;
	t_vec		vec;

	tmp = mlx->obj->begin;
	dist = -1.0;
	while (tmp)
	{
		if ((res = touch(tmp->obj, &mlx->pos_all_pix[pix], &mlx->cam->coord) > 0))
		{
			if (dist == -1.0)
				dist = res;
			else if (res < dist)
			{
				mlx->cur_obj = tmp->obj;
				dist = res;
			}
		}
		tmp = tmp->next;
	}
	return (dist);
}
