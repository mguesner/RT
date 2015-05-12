/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 10:28:41 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/12 11:25:02 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdlib.h>
//----------------------- parser manuel
t_obj_list_begin	*p(void)
{
	t_obj_list_begin *o;

	o = malloc(sizeof(t_obj_list_begin));
	o->begin = malloc(sizeof(t_obj_list));
	o->end = NULL;
	o->size = 1;
	o->begin->obj = malloc(sizeof(t_sphere));
	o->begin->obj->type = SPHERE;
	o->begin->obj->coord.x = 5000.0;
	o->begin->obj->coord.y = 10.0;
	o->begin->obj->coord.z = 500.0;
	o->begin->obj->color.a = 0;
	o->begin->obj->color.r = 100;
	o->begin->obj->color.g = 40;
	o->begin->obj->color.b = 20;
	o->begin->next = NULL;
	return (o);
}
//-----------------------
t_camera			*calc_cam(void)
{
	t_camera *o;

	o = malloc(sizeof(t_camera));
	o->type = NBOBJTYPE;
	o->coord.x = 10;
	o->coord.y = 10;
	o->coord.z = 540;
	o->pix_hg.x = 1010.0;
	o->pix_hg.y = -950.0;
	o->pix_hg.z = 1081.0;
	o->pix_hd.x = 1010.0;
	o->pix_hd.y = 970.0;
	o->pix_hd.z = 1081.0;
	o->pix_bg.x = 1010.0;
	o->pix_bg.y = -950.0;
	o->pix_bg.z = 1.0;
	return (o);
}

int expose_hook(t_libx *mlx)
{
	start(mlx);
	return (0);
}

void	usage(void)
{
	ft_putstr("usage: ./RT [scene file]\n");
}

int		main(int argc, char **argv)
{
	t_libx				*mlx;
	t_obj_list_begin	*obj;
	t_camera			*cam;

	if (argc != 2)
		usage();
	(void)(argv);
	cam = calc_cam();
	// parser(argv[1]);
	obj = p();
	mlx = mlx_struct_init(WIDTH, HEIGHT, "lol");
	mlx->obj = obj;
	mlx->cam = cam;
	mlx->pos_all_pix = precalc_vec_cam(cam);
	mlx_loop_hook(mlx->mlx, expose_hook, mlx);
	mlx_loop(mlx->mlx);
}
