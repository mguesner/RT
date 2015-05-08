/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 11:07:26 by eruffieu          #+#    #+#             */
/*   Updated: 2015/04/02 10:49:27 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	calc_vect_dir_cam(t_all *c, t_vector *current_pix)
{
	t_vector	ray;
	double		ratio;

	ray.x = current_pix->x - c->camera->pos->x;
	ray.y = current_pix->y - c->camera->pos->y;
	ray.z = current_pix->z - c->camera->pos->z;
	ratio = sqrt((ray.x * ray.x) + (ray.y * ray.y) + (ray.z * ray.z));
	c->dir_vect_cam->x = ray.x / ratio;
	c->dir_vect_cam->y = ray.y / ratio;
	c->dir_vect_cam->z = ray.z / ratio;
}

static void	pos_pixel(t_all *c)
{
	t_vector	dir_vect_y;
	t_vector	dir_vect_x;
	t_vector	*current_pix;

	if (!(current_pix = (t_vector *)malloc(sizeof(t_vector))))
		exit (0);
	dir_vect_y.x = c->camera->pos_bg->x - c->camera->pos_hg->x;
	dir_vect_y.y = c->camera->pos_bg->y - c->camera->pos_hg->y;
	dir_vect_y.z = c->camera->pos_bg->z - c->camera->pos_hg->z;
	dir_vect_x.x = c->camera->pos_hd->x - c->camera->pos_hg->x;
	dir_vect_x.y = c->camera->pos_hd->y - c->camera->pos_hg->y;
	dir_vect_x.z = c->camera->pos_hd->z - c->camera->pos_hg->z;
	current_pix->x = c->camera->pos_hg->x +
	((dir_vect_x.x / 1000.0) * c->x_pix) + ((dir_vect_y.x / 1000.0) * c->y_pix);
	current_pix->y = c->camera->pos_hg->y +
	((dir_vect_x.y / 1000.0) * c->x_pix) + ((dir_vect_y.y / 1000.0) * c->y_pix);
	current_pix->z = c->camera->pos_hg->z +
	((dir_vect_x.z / 1000.0) * c->x_pix) + ((dir_vect_y.z / 1000.0) * c->y_pix);
	calc_vect_dir_cam(c, current_pix);
}

void		check_run(t_all *c, t_lst *temp)
{
	double	dist;

	dist = 0;
	if (ft_strcmp(temp->obj->type, "sphere") == 0)
		dist = dist_sphere(c, temp);
	else if (ft_strcmp(temp->obj->type, "cylinder") == 0)
		dist = dist_cylinder(c, temp);
	else if (ft_strcmp(temp->obj->type, "plan") == 0)
		dist = dist_plan(c, temp);
	else if (ft_strcmp(temp->obj->type, "cone") == 0)
		dist = dist_cone(c, temp);
	if (dist > 0.0 && dist < c->dist_max)
	{
		c->first_obj = temp;
		c->dist_max = dist;
	}
}

void		raytrace(t_all *c)
{
	t_lst	*temp;

	c->x_pix = 0;
	while (c->x_pix < 1000)
	{
		c->y_pix = 0;
		while (c->y_pix < 1000)
		{
			temp = c->list;
			pos_pixel(c);
			c->dist_max = 1000000000000.0;
			while(temp)
			{
				check_run(c, temp);
				temp = temp->next;
			}
			if (c->dist_max != 1000000000000.0)
				draw(c);
			(c->y_pix)++;
		}
		(c->x_pix)++;
	}
	mlx_put_image_to_window(c->libx->mlx, c->libx->win, c->libx->img, 0, 0);
}
