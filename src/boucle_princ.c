/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boucle_princ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 17:34:15 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/19 15:36:48 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>
#include <stdlib.h>

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
			(mlx->pix[(pix_x + pix_y * WIDTH)])->dist =
				inters(mlx, (pix_x + pix_y * WIDTH), pix_x, pix_y);
			calc_lum(mlx, mlx->pix[(pix_x + pix_y * WIDTH)]);
			pix_x++;
		}
		pix_y++;
	}
	antialiasing(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
	ft_bzero(mlx->data, ((1079) * (mlx->size_line) + 1919 * (mlx->bpp / 8)));
}
