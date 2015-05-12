/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 10:39:28 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/12 15:24:31 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>

t_obj_list_begin	parser(char *file_name)
{
	int			fd;
	char	*line;
	// char		*file;
	// struct stat	buf;
	t_pars		e;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		error(errno);
	init_pars(&e);
	// if (fstat(fd, &buf))
	// 	error(errno);
	// file = mmap(0, buf.st_size, PROT_READ, MAP_FILE, fd, 0);
	// parse_file(&e, file);
	while (get_next_line(fd, &line) > 0)
	{
		check_line(line, &e);
		ft_strdel(&line);
		e.nb_line++;
	}
	check_pars_err(e);

	/*
	*	DEBUG
	*/

	t_obj_list *tmp;

	tmp = e.obj_lst.begin;
	while (tmp)
	{
		if (tmp->obj->type == CAM)
		{
			t_camera *cam = (t_camera *)tmp->obj;
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
		tmp = tmp->next;
	}
	return (e.obj_lst);
}
