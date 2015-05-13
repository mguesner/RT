/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 10:28:41 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/12 17:18:57 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdlib.h>
#include <stdio.h>
//----------------------- parser manuel
// t_obj_list_begin	*p(void)
// {
// 	t_obj_list_begin *o;
// 	t_obj_list		*p;
// 	t_obj			*plan;
// 	t_obj_list		*pl;
// 	t_obj			*planl;
// 	plan = malloc(sizeof(t_plane));
// 	p = malloc(sizeof(t_obj_list));
// 	planl = malloc(sizeof(t_plane));
// 	pl = malloc(sizeof(t_obj_list));
// 	o = malloc(sizeof(t_obj_list_begin));
// 	o->begin = malloc(sizeof(t_obj_list));
// 	o->end = NULL;
// 	o->size = 1;
// 	o->begin->obj = malloc(sizeof(t_sphere));
// 	o->begin->obj->type = SPHERE;
// 	o->begin->obj->coord.x = 5000.0;
// 	o->begin->obj->coord.y = 10.0;
// 	o->begin->obj->coord.z = 500.0;
// 	o->begin->obj->color.a = 0;
// 	o->begin->obj->color.r = 150;
// 	o->begin->obj->color.g = 0;
// 	o->begin->obj->color.b = 150;
// 	((t_sphere *)o->begin->obj)->radius = 2000;
// 	plan->type = PLANE;
// 	plan->coord.x = 7000;
// 	plan->coord.y = 10;
// 	plan->coord.z = 500;
// 	planl->type = LIGHT;
// 	planl->coord.x = 3000;
// 	planl->coord.y = -1000;
// 	planl->coord.z = 500;
// 	plan->color.r = 0;
// 	plan->color.g = 100;
// 	plan->color.b = 255;
// 	((t_plane *)plan)->d = -1;
// 	((t_plane *)plan)->norm.x = -1;
// 	((t_plane *)plan)->norm.y = 0;
// 	((t_plane *)plan)->norm.z = 0;
// 	p->obj = plan;
// 	pl->obj = planl;
// 	o->begin->next = p;
// 	p->next = pl;
// 	pl->next = NULL;
// 	return (o);
// }
// //-----------------------
// t_camera			*calc_cam(void)
// {
// 	t_camera *o;


// 	o = malloc(sizeof(t_camera));
// 	o->type = NBOBJTYPE;
// 	o->coord.x = 10;
// 	o->coord.y = 10;
// 	o->coord.z = 540;
// 	o->pix_hg.x = 1010.0;
// 	o->pix_hg.y = -950.0;
// 	o->pix_hg.z = 1081.0;
// 	o->pix_hd.x = 1010.0;
// 	o->pix_hd.y = 970.0;
// 	o->pix_hd.z = 1081.0;
// 	o->pix_bg.x = 1010.0;
// 	o->pix_bg.y = -950.0;
// 	o->pix_bg.z = 1.0;
// 	return (o);
// }

int expose_hook(t_libx *mlx)
{
	start(mlx);
	return (0);
}

static void	usage(void)
{
	ft_putstr("usage: ./RT [scene file]\n");
}

int			main(int argc, char **argv)
{
	t_libx				*mlx;
	t_obj_list_begin	obj;
	t_camera			*cam;

	if (argc != 2)
		usage();
	// (void)(argv);
	// cam = calc_cam();
	obj = parser(argv[1]);
	t_obj_list *tmp;

	tmp = obj.begin;
	while (tmp)
	{
		if (tmp->obj->type == CAM)
		{

			cam = (t_camera *)tmp->obj;
			printf("type : CAMERA, coord : (%f, %f, %f), color : (%d, %d, %d, %d), dir : (%f, %f, %f)\n"
				, cam->coord.x, cam->coord.y, cam->coord.z, cam->color.a, cam->color.r, cam->color.g, cam->color.b
				, cam->dir.x, cam->dir.y, cam->dir.z);
		}
		else if (tmp->obj->type == LIGHT)
		{
			t_light *light = (t_light *)tmp->obj;
			printf("type : LIGHT, coord : (%f, %f, %f), color : (%d, %d, %d, %d)\n"
				, light->coord.x, light->coord.y, light->coord.z, light->color.a, light->color.r, light->color.g, light->color.b);
		}
		else if (tmp->obj->type == PLANE)
		{
			t_plane *plane = (t_plane *)tmp->obj;
			printf("type : PLANE, coord : (%f, %f, %f), normal : (%f, %f, %f), color : (%d, %d, %d, %d)\n"
				, plane->coord.x, plane->coord.y, plane->coord.z,
				plane->norm.x, plane->norm.y, plane->norm.z, plane->color.a, plane->color.r, plane->color.g, plane->color.b);
		}
		else if (tmp->obj->type == SPHERE)
		{
			t_sphere *sphere = (t_sphere *)tmp->obj;
			printf("type : SPHERE, coord : (%f, %f, %f), radius : %f, color : (%d, %d, %d, %d)\n"
				, sphere->coord.x, sphere->coord.y, sphere->coord.z,
				sphere->radius, sphere->color.a, sphere->color.r, sphere->color.g, sphere->color.b);
		}
		else if (tmp->obj->type == CONE)
		{
			t_cone *cone = (t_cone *)tmp->obj;
			printf("type : CONE, coord : (%f, %f, %f), angle : %d, color : (%d, %d, %d, %d)\n"
				, cone->coord.x, cone->coord.y, cone->coord.z,
				cone->angle, cone->color.a, cone->color.r, cone->color.g, cone->color.b);
		}
		tmp = tmp->next;
	}
	// obj = p();
	mlx = mlx_struct_init(WIDTH, HEIGHT, "lol");
	mlx->obj = &obj;
	mlx->cam = cam;
	mlx->cam->pix_bg.x = 1010;
	mlx->cam->pix_bg.y = -950.0;
	mlx->cam->pix_bg.z = 10;
	mlx->cam->pix_hg.x = 1010;
	mlx->cam->pix_hg.y = -950.0;
	mlx->cam->pix_hg.z = 1090;
	mlx->cam->pix_hd.x = 1010;
	mlx->cam->pix_hd.y = 970;
	mlx->cam->pix_hd.z = 1090;
	mlx->pos_all_pix = precalc_vec_cam(cam);
	mlx_loop_hook(mlx->mlx, expose_hook, mlx);
	mlx_loop(mlx->mlx);
}
