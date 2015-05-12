/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boucle_princ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 17:34:15 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/12 11:38:55 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>
void		go(t_libx *mlx, int pix, int pix_x, int pix_y)
{
	t_obj_list	*tmp;
	double		dist;
	double		res;

	tmp = mlx->obj->begin;
	dist = 0.0;
	while (tmp)
	{
		if ((res = touch(tmp->obj, &mlx->pos_all_pix[pix], &mlx->cam->coord) > 0))
			dist = res;
		tmp = tmp->next;
	}
	if (dist > 0)
		set_pixel_to_img(mlx, pix_x, pix_y, &mlx->obj->begin->obj->color);
}

void		start(t_libx *mlx)
{
	int		pix_x;
	int		pix_y;

	pix_y = 0;
	while (pix_y < mlx->height)
	{
		pix_x = 0;
		while (pix_x < mlx->width)
		{
			go(mlx, (pix_x + pix_y * WIDTH), pix_x, pix_y);
			pix_x++;
		}
		pix_y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
}
