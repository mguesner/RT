/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 10:28:41 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/31 16:05:31 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdlib.h>
#include <stdio.h>
#include <matrice.h>

int	mouse_motion(int x, int y, t_libx *mlx)
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
	if (mlx->state == 0)
	{
		if (keycode == 53)
			exit (0);
	}
	else if (mlx->state == 2)
	{
		if (keycode == 53)
		{
			mlx->state = 0;
			ft_bzero(mlx->data, ((1079) * (mlx->size_line) + 1919 * (mlx->bpp / 8)));
			mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
			clean_mlx(mlx);
			menu_rt(mlx);
		}
		else if (keycode == 126 || keycode == 125 || keycode == 123 ||
			keycode == 124 || keycode == 69 || keycode == 78)
		{
			key_translate_cam(keycode, mlx);
			mlx->superint = 1;
		}
		else if (keycode == 0 || keycode == 2 || keycode == 1 ||
			keycode == 12 || keycode == 13 || keycode == 14)
		{
			key_rotate_cam(keycode, mlx);
			mlx->superint = 1;
		}
	}
	return (0);
}

int	mouse_press(int code, int x, int y, t_libx *mlx)
{
	t_list				*tmp;
	t_camera			*cam;
	char				*name;

	if (mlx->state == 0)
	{
		if (x >= 0 && x < 100)
		{
			tmp = mlx->files;
			y /= 20;
			while (tmp && y > 0)
			{
				tmp = tmp->next;
				y--;
			}
			if (tmp && !y)
			{
				if (tmp->type == 0)
				{
					cd_custom(mlx, tmp->file);
					mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
					menu_rt(mlx);
				}
				else
				{
					mlx->state = 1;
					name = ft_strtrijoin(mlx->current_dir, "/", tmp->file);
					lex_pars(name, mlx);
					ft_memdel((void **)&name);
					cam = mlx->cam;
					t_point	ori = cam->coord;
					t_vec	dir = make_vec(cam->dir, ori);
					// double	dist = norme(dir);
					dir = normalize(dir);
					t_vec	norm = {1, 0, 0};
					t_vec	up_vec = {0, 0, 1};
					t_vec	right_vec = {0, -1, 0};
					t_vec	axe = vector(dir, norm);
					if (!axe.x && !axe.y && !axe.z)
					{
						cam->up_vec = up_vec;
						cam->right_vec = right_vec;
					}
					else
					{
						double	rot[3][3];
						get_rotate(axe, scalar(dir, norm), rot);
						cam->up_vec = normalize(do_rotate_vec(rot, up_vec));
						cam->right_vec = normalize(do_rotate_vec(rot, right_vec));
					}
					cam->pix_hg.x = cam->coord.x
						+ (dir.x * VIEWPLANEDIST + cam->up_vec.x * (VIEWPLANEHEIGHT / 2))
						- cam->right_vec.x * (VIEWPLANEWIDTH / 2);
					cam->pix_hg.y = cam->coord.y
						+ (dir.y * VIEWPLANEDIST + cam->up_vec.y * (VIEWPLANEHEIGHT / 2))
						- cam->right_vec.y * (VIEWPLANEWIDTH / 2);
					cam->pix_hg.z = cam->coord.z
						+ (dir.z * VIEWPLANEDIST + cam->up_vec.z * (VIEWPLANEHEIGHT / 2))
						- cam->right_vec.z * (VIEWPLANEWIDTH / 2);
					// printf("haut gauche (%f, %f, %f)\n", cam->pix_hg.x, cam->pix_hg.y, cam->pix_hg.z);
					mlx->superint = 0;
					mlx->pix = precalc_vec_cam(cam);
				}
			}
		}
	}
	else if (mlx->state == 2)
	{
		if (x >= 0 && x < WIDTH && y >= 0  && y < HEIGHT)
		{
			t_pix *current = mlx->pix[x + y * WIDTH];
			if (current->cur_obj && current->in_shadow)
				printf("Distance is %f,   you touch a %d dist to light = %f, and you are in shadow of %d at %f mm. Debug : %d\n", current->dist,current->cur_obj->type, current->light_dist ,current->in_shadow->type, current->shadow_dist, current->debug);
			else if (current->cur_obj)
				printf("Distance is %f,   you touch a %d , and you are not in shadow\n", current->dist, current->cur_obj->type);
			else
				printf("Distance is %f,   you touch nothing , and you are in shadow  WTFFFFFF   \n", current->dist);

			printf("%d\n", code);
		}
	}
	return (0);
}



// static void	usage(void)
// {
// 	ft_putstr("usage: ./RT [scene file]\n");
// }

int			main(void)
{
	t_libx				mlx;

	ft_bzero(&mlx, sizeof(t_libx));
	// if (argc != 2)
	// 	usage();
	mlx_struct_init(WIDTH, HEIGHT, "RT", &mlx);
	menu_rt(&mlx);
	mlx_loop_hook(mlx.mlx, expose_hook, &mlx);
	mlx_key_hook(mlx.window, key_hook, &mlx);
	mlx_hook(mlx.window, 4, (1L << 2), mouse_press, &mlx);
	mlx_hook(mlx.window, 6, (1L << 6), mouse_motion, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
