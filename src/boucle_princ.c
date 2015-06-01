/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boucle_princ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 17:34:15 by eruffieu          #+#    #+#             */
/*   Updated: 2015/06/01 12:33:39 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

static void print_t_point(t_point t)
{
	printf("x: %f, y: %f, z :%f\n", t.x, t.y, t.z);
}

static void	*loop(void *arg)
{
	t_libx	*mlx;
	int		i;

	mlx = (void *)arg;
	// pthread_mutex_lock(&(mlx->mutex));
	// i = mlx->current_pix;
	// mlx->current_pix += 1;
	// pthread_mutex_unlock(&(mlx->mutex));
	i = 0;
	while (i < TOTAL_PIX)
	{
		inters(mlx, i, i % WIDTH, i / WIDTH);
		calc_lum(mlx, mlx->pix[i]);
		i += 1;
	}
	return (NULL);
}

void		start(t_libx *mlx)
{
	// pthread_t	th[8];
	int			count;

	print_t_point(mlx->cam->pix_hg);
	print_t_point(mlx->cam->pix_bg);
	print_t_point(mlx->cam->pix_hd);
	print_t_point(mlx->cam->coord);
	count = 0;
	mlx->current_pix = 0;
	pthread_mutex_init(&(mlx->mutex), NULL);
	// while (count < 8)
	// {
	// 	pthread_create(&th[count], NULL, loop, mlx);
	// 	count++;
	// }
	// count = 0;
	loop(mlx);
	// while (count < 8)
	// {
	// 	pthread_join(th[count], NULL);
	// 	count++;
	// }
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
	ft_bzero(mlx->data, ((1079) * (mlx->size_line) + 1919 * (mlx->bpp / 8)));
}
