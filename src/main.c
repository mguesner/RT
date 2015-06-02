/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 10:28:41 by mguesner          #+#    #+#             */
/*   Updated: 2015/06/02 15:20:15 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdlib.h>
#include <stdio.h>
#include <matrice.h>

int		mouse_motion(int x, int y, t_libx *mlx)
{
	(void)x;
	(void)y;
	(void)mlx;
	return (0);
}

int		expose_hook(t_libx *mlx)
{
	if (mlx->state == 1 && !mlx->superint)
	{
		mlx->superint = 1;
		mlx->state = 2;
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
		mlx_string_put(mlx->mlx, mlx->window, 0, 540, 0xffffff, "LOADING...");
	}
	else if (mlx->superint)
	{
		start(mlx);
		mlx->superint = 0;
	}
	return (0);
}

int		key_hook(int keycode, t_libx *mlx)
{
	if (mlx->state == 0 && keycode == 53)
		exit (0);
	else if (mlx->state == 2)
	{
		if (keycode == 53)
		{
			mlx->state = 0;
			ft_bzero(mlx->data, ((1079) * (mlx->size_line)
				+ 1919 * (mlx->bpp / 8)));
			mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
			clean_mlx(mlx);
			menu_rt(mlx);
		}
		else if ((keycode == 126 || keycode == 125 || keycode == 123 ||
			keycode == 124 || keycode == 69 || keycode == 78)
			&& (mlx->superint = 1))
			key_translate_cam(keycode, mlx);
		else if (keycode == 0 || keycode == 2 || keycode == 1 ||
			keycode == 12 || keycode == 13 || keycode == 14)
		{
			key_rotate_cam(keycode, mlx);
			mlx->superint = 1;
		}
	}
	return (0);
}

int		mouse_press(int code, int x, int y, t_libx *mlx)
{
	t_list				*tmp;

	(void)code;
	if (mlx->state == 0 && x >= 0 && x < 100)
	{
		tmp = mlx->files;
		y = (y / 20) + 1;
		while (tmp && --y > 0)
			tmp = tmp->next;
		if (tmp && !y)
		{
			if (tmp->type == 0)
			{
				cd_custom(mlx, tmp->file);
				mlx_put_image_to_window(mlx->mlx, mlx->window
					, mlx->img, 0, 0);
				menu_rt(mlx);
			}
			else
				do_raytracing(mlx, tmp);
		}
	}
	return (0);
}

int		main(void)
{
	t_libx				mlx;

	ft_bzero(&mlx, sizeof(t_libx));
	mlx_struct_init(WIDTH, HEIGHT, "RT", &mlx);
	menu_rt(&mlx);
	mlx_loop_hook(mlx.mlx, expose_hook, &mlx);
	mlx_key_hook(mlx.window, key_hook, &mlx);
	mlx_hook(mlx.window, 4, (1L << 2), mouse_press, &mlx);
	mlx_hook(mlx.window, 6, (1L << 6), mouse_motion, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
