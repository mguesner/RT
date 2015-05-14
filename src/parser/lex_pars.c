/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 09:19:21 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/14 14:19:20 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <errno.h>
#include <stdio.h>

void					lex_pars(char *file_name, t_libx *mlx)
{
	int			fd;
	t_obj_list	*lst;
	t_obj_list	*next;
	t_pars		e;

	init_pars(&e);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		error(errno);
	lexer(fd, &e);

	//DEBUG
	// t_lex *tmp;
	// tmp = e.lex_lst.begin;
	// while (tmp)
	// {
	// 	ft_printf("type : %s, value : %s\n", tmp->token_type == 0 ? "WORD"
	// 		: tmp->token_type == 1 ? "VALUE"
	// 		: tmp->token_type == 2 ? "OPENSCOPE"
	// 		: tmp->token_type == 3 ? "CLOSESCOPE"
	// 		: "VECTOR"
	// 		,tmp->value);
	// 	tmp = tmp->next;
	// }
	//END DEBUG

	parser(&e);
	check_pars_err(e);
	/*
	*	DEBUG
	*/
	// t_obj_list *tmp2;

	// tmp2 = e.obj_lst.begin;
	// ft_putstr("\nobj:\n");
	// while (tmp2)
	// {
	// 	if (tmp2->obj->type == CAM)
	// 	{

	// 		t_camera *cam = (t_camera *)tmp2->obj;
	// 		printf("type : CAMERA, coord : (%f, %f, %f), color : (%d, %d, %d, %d), dir : (%f, %f, %f)\n"
	// 			, cam->coord.x, cam->coord.y, cam->coord.z, cam->color.a, cam->color.r, cam->color.g, cam->color.b
	// 			, cam->dir.x, cam->dir.y, cam->dir.z);
	// 	}
	// 	else if (tmp2->obj->type == LIGHT)
	// 	{
	// 		t_light *light = (t_light *)tmp2->obj;
	// 		printf("type : LIGHT, coord : (%f, %f, %f), color : (%d, %d, %d, %d)\n"
	// 			, light->coord.x, light->coord.y, light->coord.z, light->color.a, light->color.r, light->color.g, light->color.b);
	// 	}
	// 	else if (tmp2->obj->type == PLANE)
	// 	{
	// 		t_plane *plane = (t_plane *)tmp2->obj;
	// 		printf("type : PLANE, coord : (%f, %f, %f), normal : (%f, %f, %f), color : (%d, %d, %d, %d)\n"
	// 			, plane->coord.x, plane->coord.y, plane->coord.z,
	// 			plane->norm.x, plane->norm.y, plane->norm.z, plane->color.a, plane->color.r, plane->color.g, plane->color.b);
	// 	}
	// 	else if (tmp2->obj->type == SPHERE)
	// 	{
	// 		t_sphere *sphere = (t_sphere *)tmp2->obj;
	// 		printf("type : SPHERE, coord : (%f, %f, %f), radius : %f, color : (%d, %d, %d, %d)\n"
	// 			, sphere->coord.x, sphere->coord.y, sphere->coord.z,
	// 			sphere->radius, sphere->color.a, sphere->color.r, sphere->color.g, sphere->color.b);
	// 	}
	// 	else if (tmp2->obj->type == CYLINDER)
	// 	{
	// 		t_cylinder *cylinder = (t_cylinder *)tmp2->obj;
	// 		printf("type : CYLINDER, coord : (%f, %f, %f), radius : %f, direction : (%f, %f, %f), color : (%d, %d, %d, %d)\n"
	// 			, cylinder->coord.x, cylinder->coord.y, cylinder->coord.z,
	// 			cylinder->radius, cylinder->dir.x, cylinder->dir.y, cylinder->dir.z
	// 			, cylinder->color.a, cylinder->color.r, cylinder->color.g, cylinder->color.b);
	// 	}
	// 	else if (tmp2->obj->type == CONE)
	// 	{
	// 		t_cone *cone = (t_cone *)tmp2->obj;
	// 		printf("type : CONE, coord : (%f, %f, %f), angle : %f, direction : (%f, %f, %f), color : (%d, %d, %d, %d)\n"
	// 			, cone->coord.x, cone->coord.y, cone->coord.z,
	// 			cone->angle, cone->dir.x, cone->dir.y, cone->dir.z
	// 			, cone->color.a, cone->color.r, cone->color.g, cone->color.b);
	// 	}
	// 	tmp2 = tmp2->next;
	// }

	//END DEBUG

	lst = e.obj_lst.begin;
	next = lst;
	while (next)
	{
		next = next->next;
		if (lst->obj->type == CAM)
		{
			mlx->cam = (t_camera *)lst->obj;
			ft_memdel((void **)&lst);
		}
		else if (lst->obj->type == LIGHT)
		{
			if (!mlx->spots.size)
				mlx->spots.begin = lst;
			else
				mlx->spots.end->next = lst;
			mlx->spots.size++;
			mlx->spots.end = lst;
			lst->next = NULL;
		}
		else
		{
			if (!mlx->obj.size)
				mlx->obj.begin = lst;
			else
				mlx->obj.end->next = lst;
			mlx->obj.size++;
			mlx->obj.end = lst;
			lst->next = NULL;
		}
		lst = next;
	}
	clean_pars(&e);
}
