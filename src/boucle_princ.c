/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boucle_princ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 17:34:15 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/11 16:11:22 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>
void		go(t_libx *mlx, int pix_x, int pix_y)
{
	double d;
	d = dist_sphere(mlx, pix_x, pix_y);
	if (d > 0)
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
			go(mlx, pix_x, pix_y);
			pix_x++;
		}
		pix_y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
}
