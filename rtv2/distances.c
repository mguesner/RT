/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 13:29:38 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/14 11:50:45 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	distrotion_vector(t_all *c, t_lst *temp)
{
	c->rotation->x = c->dir_vect_cam->x;
	c->rotation->y = c->dir_vect_cam->y;
	c->rotation->z = c->dir_vect_cam->z;
	c->rotation->x = (c->rotation->x * 1.0);
	c->rotation->y = (c->rotation->y * cos((temp->obj->angle->x / 180.0) * M_PI) +  c->rotation->z * -sin((temp->obj->angle->x / 180.0) * M_PI));
	c->rotation->z = (c->rotation->y * sin((temp->obj->angle->x / 180.0) * M_PI) + c->rotation->z * cos((temp->obj->angle->x / 180.0) * M_PI));
	c->rotation->x = (c->rotation->x * cos((temp->obj->angle->y / 180.0) * M_PI) + c->rotation->z * sin((temp->obj->angle->y / 180.0) * M_PI));
	c->rotation->y = (c->rotation->y * 1.0);
	c->rotation->z = (c->rotation->x * -sin((temp->obj->angle->y / 180.0) * M_PI) + c->rotation->z * cos((temp->obj->angle->y / 180.0) * M_PI));
	c->rotation->x = (c->rotation->x * cos((temp->obj->angle->z / 180.0) * M_PI) + c->rotation->y * -sin((temp->obj->angle->z / 180.0) * M_PI));
	c->rotation->y = (c->rotation->x * sin((temp->obj->angle->z / 180.0) * M_PI) + c->rotation->y * cos((temp->obj->angle->z / 180.0) * M_PI));
	c->rotation->z = (c->rotation->z * 1.0);
}

double	dist_sphere(t_all *c, t_lst *temp)
{
	double	sa;
	double	sb;
	double	sc;
	double det;

	distrotion_vector(c, temp);
	sa = (c->rotation->x * c->rotation->x) +
		(c->rotation->y * c->rotation->y) +
		(c->rotation->z * c->rotation->z);
	sb = 2.0 * c->rotation->x *
		(c->camera->pos->x - temp->obj->pos->x) + 2.0 *
		c->rotation->y * (c->camera->pos->y - temp->obj->pos->y) + 2.0
		* c->rotation->z * (c->camera->pos->z - temp->obj->pos->z);
	sc = (temp->obj->pos->x * temp->obj->pos->x) +
		(temp->obj->pos->y * temp->obj->pos->y) +
		(temp->obj->pos->z * temp->obj->pos->z) +
		(c->camera->pos->x * c->camera->pos->x) +
		(c->camera->pos->y * c->camera->pos->y) +
		(c->camera->pos->z * c->camera->pos->z) +
		-2.0 * (temp->obj->pos->x * c->camera->pos->x +
		temp->obj->pos->y * c->camera->pos->y +
		temp->obj->pos->z * c->camera->pos->z) -
		(temp->obj->other * temp->obj->other);
	det = pow(sb, 2) - 4.0 * sa * sc;
	if (det > 0)
	{
		double ret = (-(sb) + sqrt(det)) / 2.0 * sa;
		double ret2 = (-(sb) - sqrt(det)) / 2.0 * sa;
		return (ret2 > 0.0001 ? ret2 : ret);
	}
	return (-1);
}

double	dist_plan(t_all *c, t_lst *temp)
{
	distrotion_vector(c, temp);
	return (-((temp->obj->pos->x * c->camera->pos->x
		+ temp->obj->pos->y * c->camera->pos->y +
		temp->obj->pos->z * c->camera->pos->z +
		temp->obj->other) /
		(temp->obj->pos->x * c->rotation->x +
		temp->obj->pos->y * c->rotation->y +
		temp->obj->pos->z * c->rotation->z)));
}

double	dist_cylinder(t_all *c, t_lst *temp)
{
	double	sa;
	double	sb;
	double	sc;

	distrotion_vector(c, temp);
	sa = (c->rotation->x * c->rotation->x) +
		(c->rotation->y * c->rotation->y);
	sb = 2.0 * (c->rotation->x *
		(c->camera->pos->x - temp->obj->pos->x) +
		c->rotation->y * (c->camera->pos->y - temp->obj->pos->y));
	sc = (((c->camera->pos->x - temp->obj->pos->x) *
		(c->camera->pos->x - temp->obj->pos->x)) +
		((c->camera->pos->y - temp->obj->pos->y) *
		(c->camera->pos->y - temp->obj->pos->y)) -
		(temp->obj->other * temp->obj->other));
	if ((sb * sb - 4.0 * sa * sc) > 0)
		return (((-(sb)-sqrt((sb * sb - 4.0 * sa * sc))) / 2.0 * sa));
	else
		return (-1);
}

double	dist_cone(t_all *c, t_lst *temp)
{
	double	sa;
	double	sb;
	double	sc;
	double	res_angle;

	distrotion_vector(c, temp);
	res_angle = pow(tan(temp->obj->other * M_PI / 180.0), 2.0);
	sa = (c->rotation->x * c->rotation->x) +
		(c->rotation->y * c->rotation->y) -
		res_angle * (c->rotation->z * c->rotation->z);
	sb = 2.0 * (c->rotation->x *
		(c->camera->pos->x - temp->obj->pos->x) +
		c->rotation->y * (c->camera->pos->y - temp->obj->pos->y) -
		c->rotation->z * (c->camera->pos->z - temp->obj->pos->z) * res_angle);
	sc = (((c->camera->pos->x - temp->obj->pos->x) * (c->camera->pos->x - temp->obj->pos->x)) +
			((c->camera->pos->y - temp->obj->pos->y) * (c->camera->pos->y - temp->obj->pos->y)) -
			((c->camera->pos->z - temp->obj->pos->z) * (c->camera->pos->z - temp->obj->pos->z)) * res_angle);
	if ((sb * sb - 4.0 * sa * sc) > 0)
		return (((-(sb)-sqrt((sb * sb) - 4.0 * sa * sc))) / 2.0 * sa);
	else
		return (-1);
}
