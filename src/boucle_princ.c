/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boucle_princ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 17:34:15 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/13 09:32:37 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>
#include <stdlib.h>
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
		{
			if (dist != 0)
			{
				if (res < dist)
					set_pixel_to_img(mlx, pix_x, pix_y, &tmp->obj->color);
			}
			else
					set_pixel_to_img(mlx, pix_x, pix_y, &tmp->obj->color);
			dist = res;
		}
		tmp = tmp->next;
	}
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
<<<<<<< HEAD
=======
	// printf("put\n");
>>>>>>> 38035632c242b60205964bfaeef5d4d064898a0d
	ft_bzero(mlx->data, ((1079) * (mlx->size_line) + 1919 * (mlx->bpp / 8)));
}
