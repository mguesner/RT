/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boucle_princ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 17:34:15 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/26 13:16:25 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

static void	*loop(void *arg)
{
	t_libx	*mlx;
	int		i;

	mlx = (void *)arg;
	pthread_mutex_lock(&(mlx->mutex));
	i = mlx->current_pix;
	mlx->current_pix += 1;
	pthread_mutex_unlock(&(mlx->mutex));
	while (i < TOTAL_PIX)
	{
		inters(mlx, i, i % WIDTH, i / WIDTH);
 		calc_lum(mlx, mlx->pix[i]);
 		i += 8;
	}
	return (NULL);
}

void		start(t_libx *mlx)
{
	pthread_t	th[8];

	mlx->current_pix = 0;
 	int count = 0;
 	pthread_mutex_init(&(mlx->mutex), NULL);
	while (count < 8)
	{
		pthread_create(&th[count], NULL, loop, mlx);
		count ++;
	}
	count = 0;
	while (count < 8)
	{
		pthread_join(th[count], NULL);
		count++;
	}
 	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
 	ft_bzero(mlx->data, ((1079) * (mlx->size_line) + 1919 * (mlx->bpp / 8)));
}


// void		start(t_libx *mlx)
// {
// 	int		j;

// 	j = 0;
// 	while (j < TOTAL_PIX)
// 	{
// 		mlx->pix[j]->dist = inters(mlx, j, j % WIDTH, j / WIDTH);
// 		calc_lum(mlx, mlx->pix[j]);
// 		j++;
// 	}
// 	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
// 	ft_bzero(mlx->data, ((1079) * (mlx->size_line) + 1919 * (mlx->bpp / 8)));
// }

	// int	pix_x;
	// int pix_y;

	// pix_y = 0;
	// while (pix_y < mlx->height)
	// {
	// 	pix_x = 0;
	// 	while (pix_x < mlx->width)
	// 	{
	// 		*(t_point *)(&mlx->pix[pix_x + pix_y * WIDTH]->pos_pix_vec) =
	// 			do_rotate(rot, *(t_point *)(&mlx->pix[pix_x + pix_y * WIDTH]->pos_pix_vec));
	// 		pix_x++;
	// 	}
	// 	pix_y++;
	// }
