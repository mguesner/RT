/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boucle_princ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 17:34:15 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/26 12:27:57 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>
#include <stdlib.h>

void		start(t_libx *mlx)
{
	int		j;

	j = 0;
	while (j < TOTAL_PIX)
	{
		inters(mlx, j, j % WIDTH, j / WIDTH);
		calc_lum(mlx, mlx->pix[j]);
		j++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
	ft_bzero(mlx->data, ((1079) * (mlx->size_line) + 1919 * (mlx->bpp / 8)));
}
