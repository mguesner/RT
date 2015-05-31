/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boucle_princ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 17:34:15 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/30 17:16:35 by mguesner         ###   ########.fr       */
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
	int			count;

	count = 0;
	mlx->current_pix = 0;
	pthread_mutex_init(&(mlx->mutex), NULL);
	while (count < 8)
	{
		pthread_create(&th[count], NULL, loop, mlx);
		count++;
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
