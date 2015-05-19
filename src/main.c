/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 10:28:41 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/19 15:57:52 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdlib.h>
#include <stdio.h>
#include <matrice.h>

int	mouse_press(int code, int x, int y, t_libx *mlx)
{

	t_pix *current = mlx->pix[x + y * WIDTH];
	if (current->cur_obj && current->in_shadow)
		printf("Distance is %f,   you touch a %d dist to light = %f, and you are in shadow of %d at %f mm.\n", current->dist,current->cur_obj->type, current->light_dist ,current->in_shadow->type, current->shadow_dist);
	else if (current->cur_obj)
		printf("Distance is %f,   you touch a %d , and you are not in shadow\n", current->dist, current->cur_obj->type);
	else
		printf("Distance is %f,   you touch nothing , and you are in shadow  WTFFFFFF   \n", current->dist);

	printf("%d\n", code);
	return (0);
}

int	mouse_motion(int x, int y, t_libx *mlx)
{
	(void)x;
	(void)y;
	(void)mlx;
	return (0);
}


int		expose_hook(t_libx *mlx)
{
	start(mlx);
	return (0);
}

int		key_hook( int keycode, t_libx *mlx)
{
	(void)(mlx);
	(void)(keycode);
	exit(0);
	return (0);
}

static void	usage(void)
{
	ft_putstr("usage: ./RT [scene file]\n");
}

int			main(int argc, char **argv)
{
	t_libx				mlx;
	t_camera *cam;

	ft_bzero(&mlx, sizeof(t_libx));
	if (argc != 2)
		usage();
	mlx_struct_init(WIDTH, HEIGHT, "lol", &mlx);
	lex_pars(argv[1], &mlx);
	cam = mlx.cam;
	t_point	ori = cam->coord;
	t_vec	dir = make_vec(cam->dir, ori);
	double	dist = norme(dir);
	t_vec	norm = {1, 0, 0};
	t_vec	axe = vector(dir, norm);
	t_point	pix_bg = {dist, -(WIDTH / 2), (HEIGHT / 2)};
	t_point	pix_hg = {dist, -(WIDTH / 2), -(HEIGHT / 2)};
	t_point	pix_hd = {dist, (WIDTH / 2), -(HEIGHT / 2)};
	if (!axe.x && !axe.y && !axe.z)
	{
		cam->pix_bg = pix_bg;
		cam->pix_hg = pix_hg;
		cam->pix_hd = pix_hd;
	}
	else
	{
		double	rot[3][3];
		get_rotate(axe, scalar(dir, norm), rot);
		cam->pix_bg = do_rotate(rot, pix_bg);
		cam->pix_bg = translate(cam->pix_bg, *(t_vec *)(&cam->coord));
		cam->pix_hg = do_rotate(rot, pix_hg);
		cam->pix_hg = translate(cam->pix_hg, *(t_vec *)(&cam->coord));
		cam->pix_hd = do_rotate(rot, pix_hd);
		cam->pix_hd = translate(cam->pix_hd, *(t_vec *)(&cam->coord));
	}
	mlx.pix = precalc_vec_cam(cam);
	mlx_loop_hook(mlx.mlx, expose_hook, &mlx);
	mlx_key_hook(mlx.window, key_hook, &mlx);
	mlx_hook(mlx.window, 4, (1L << 2), mouse_press, &mlx);
	mlx_hook(mlx.window, 6, (1L << 6), mouse_motion, &mlx);
	mlx_loop(mlx.mlx);
}
