/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 10:28:41 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/12 14:27:07 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdlib.h>
//----------------------- parser manuel
t_obj_list_begin	*p(void)
{
	t_obj_list_begin *o;
	t_obj_list		*p;
	t_obj			*plan;
	t_obj_list		*pl;
	t_obj			*planl;
	plan = malloc(sizeof(t_plane));
	p = malloc(sizeof(t_obj_list));
	planl = malloc(sizeof(t_plane));
	pl = malloc(sizeof(t_obj_list));
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
	o->begin->obj->color.r = 150;
	o->begin->obj->color.g = 0;
	o->begin->obj->color.b = 150;
	((t_sphere *)o->begin->obj)->radius = 2000;
	plan->type = PLANE;
	plan->coord.x = 7000;
	plan->coord.y = 10;
	plan->coord.z = 500;
	planl->type = LIGHT;
	planl->coord.x = 3000;
	planl->coord.y = -1000;
	planl->coord.z = 500;
	plan->color.r = 0;
	plan->color.g = 100;
	plan->color.b = 255;
	((t_plane *)plan)->coord.z = -1;
	((t_plane *)plan)->norm.x = -1;
	((t_plane *)plan)->norm.y = 0;
	((t_plane *)plan)->norm.z = 0;
	p->obj = plan;
	pl->obj = planl;
	o->begin->next = p;
	p->next = pl;
	pl->next = NULL;
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
