/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_lum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 07:36:16 by eruffieu          #+#    #+#             */
/*   Updated: 2015/04/02 11:05:18 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double	calc_shadows(t_all *c, t_lst *temp)
{
	double	dist;

	dist = 0.0;
	if (ft_strcmp(temp->obj->type, "sphere") == 0)
		dist = dist_sphere(c, temp);
	else if (ft_strcmp(temp->obj->type, "cylinder") == 0)
		dist = dist_cylinder(c, temp);
	else if (ft_strcmp(temp->obj->type, "plan") == 0)
		dist = dist_plan(c, temp);
	else if (ft_strcmp(temp->obj->type, "cone") == 0)
		dist = dist_cone(c, temp);
	if (dist >= c->dist_spot || dist < 0.0)
		return (-1);
	return(dist);
}

static int		touch_obj(t_all *c, t_vector *hit_pos)
{
	int			touch;
	t_lst		*temp;
	t_vector	*save_cam_pos;

	if (!(save_cam_pos = (t_vector *)malloc(sizeof(t_vector))))
		exit (0);
	touch = 0;
	save_cam_pos->x = c->camera->pos->x;
	save_cam_pos->y = c->camera->pos->y;
	save_cam_pos->z = c->camera->pos->z;
	c->camera->pos->x = hit_pos->x;
	c->camera->pos->y = hit_pos->y;
	c->camera->pos->z = hit_pos->z;
	temp = c->list;
	while(temp)
	{
		if (temp != c->first_obj && calc_shadows(c, temp) > 0)
				touch = 1;
		temp = temp->next;
	}
	c->camera->pos->x = save_cam_pos->x;
	c->camera->pos->y = save_cam_pos->y;
	c->camera->pos->z = save_cam_pos->z;
	if (touch == 1)
		return (1);
	return (0);
}

double			calc_dist_spot(t_all *c)
{
	t_vector	*dir;
	t_vector	*hit_pos;

	if (!(hit_pos = (t_vector *)malloc(sizeof(t_vector))) ||
		!(dir = (t_vector *)malloc(sizeof(t_vector))))
		exit (0);
	distrotion_vector(c, c->first_obj);
	hit_pos->x = c->camera->pos->x + c->dist_max * c->rotation->x;
	hit_pos->y = c->camera->pos->y + c->dist_max * c->rotation->y;
	hit_pos->z = c->camera->pos->z + c->dist_max * c->rotation->z;
	dir->x = c->list_spot->obj->pos->x - hit_pos->x;
	dir->y = c->list_spot->obj->pos->y - hit_pos->y;
	dir->z = c->list_spot->obj->pos->z - hit_pos->z;
	c->dist_spot = sqrt(pow(dir->x, 2) + pow(dir->y, 2) + pow(dir->z, 2));
	c->dir_vect_cam->x = dir->x / c->dist_spot;
	c->dir_vect_cam->y = dir->y / c->dist_spot;
	c->dir_vect_cam->z = dir->z / c->dist_spot;
	if (touch_obj(c, hit_pos) == 1)
		return (c->list_spot->obj->other - (c->list_spot->obj->other / 8.0));
	return (c->dist_spot);
}
