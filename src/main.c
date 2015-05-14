/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 10:28:41 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/14 13:39:25 by mguesner         ###   ########.fr       */
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
	t_libx				mlx;
	// t_obj_list_begin	obj;
	// t_camera			*cam;

	if (argc != 2)
		usage();
	mlx.spots = ft_memalloc(sizeof(t_obj_list_begin));
	mlx.obj = ft_memalloc(sizeof(t_obj_list_begin));
	lex_pars(argv[1], &mlx);

	// DEBUG

	t_camera *cam = mlx.cam;
	printf("type : CAMERA, coord : (%f, %f, %f), color : (%d, %d, %d, %d), dir : (%f, %f, %f)\n"
				, cam->coord.x, cam->coord.y, cam->coord.z, cam->color.a, cam->color.r, cam->color.g, cam->color.b
				, cam->dir.x, cam->dir.y, cam->dir.z);
	t_obj_list	*spots = mlx.spots->begin;
	while (spots)
	{
		t_light *light = (t_light *)spots->obj;
		printf("type : LIGHT, coord : (%f, %f, %f), color : (%d, %d, %d, %d)\n"
			, light->coord.x, light->coord.y, light->coord.z, light->color.a, light->color.r, light->color.g, light->color.b);
		spots = spots->next;
	}
	t_obj_list	*obj = mlx.obj->begin;
	while (obj)
	{
		if (obj->obj->type == PLANE)
		{
			t_plane *plane = (t_plane *)obj->obj;
			printf("type : PLANE, coord : (%f, %f, %f), normal : (%f, %f, %f), color : (%d, %d, %d, %d)\n"
				, plane->coord.x, plane->coord.y, plane->coord.z,
				plane->norm.x, plane->norm.y, plane->norm.z, plane->color.a, plane->color.r, plane->color.g, plane->color.b);
		}
		else if (obj->obj->type == SPHERE)
		{
			t_sphere *sphere = (t_sphere *)obj->obj;
			printf("type : SPHERE, coord : (%f, %f, %f), radius : %f, color : (%d, %d, %d, %d)\n"
				, sphere->coord.x, sphere->coord.y, sphere->coord.z,
				sphere->radius, sphere->color.a, sphere->color.r, sphere->color.g, sphere->color.b);
		}
		else if (obj->obj->type == CYLINDER)
		{
			t_cylinder *cylinder = (t_cylinder *)obj->obj;
			printf("type : CYLINDER, coord : (%f, %f, %f), radius : %f, direction : (%f, %f, %f), color : (%d, %d, %d, %d)\n"
				, cylinder->coord.x, cylinder->coord.y, cylinder->coord.z,
				cylinder->radius, cylinder->dir.x, cylinder->dir.y, cylinder->dir.z
				, cylinder->color.a, cylinder->color.r, cylinder->color.g, cylinder->color.b);
		}
		else if (obj->obj->type == CONE)
		{
			t_cone *cone = (t_cone *)obj->obj;
			printf("type : CONE, coord : (%f, %f, %f), angle : %f, direction : (%f, %f, %f), color : (%d, %d, %d, %d)\n"
				, cone->coord.x, cone->coord.y, cone->coord.z,
				cone->angle, cone->dir.x, cone->dir.y, cone->dir.z
				, cone->color.a, cone->color.r, cone->color.g, cone->color.b);
		}
		obj = obj->next;
	}
	// END DEBUG
	// cam = calc_cam();
	// obj = parser(argv[1]);
}
