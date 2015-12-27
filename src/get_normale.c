/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/18 14:34:10 by eruffieu          #+#    #+#             */
/*   Updated: 2015/06/01 12:52:49 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vec	cylinder_norm(t_pix *pix, t_point inter)
{
	t_point	point;

	point.x = pix->cur_obj->coord.x;
	point.y = pix->cur_obj->coord.y;
	point.z = inter.z;
	return (normalize(make_vec(inter, point)));
}

static t_vec	cone_norm(t_pix *pix, t_point inter)
{
	float	x;
	float	y;
	float	z;
	float	size;
	t_vec	vec;

	x = inter.x - pix->cur_obj->coord.x;
	y = inter.y - pix->cur_obj->coord.y;
	z = -((t_cone *)pix->cur_obj)->angle * (inter.z - pix->cur_obj->coord.z);
	size = sqrt(x * x + y * y + z * z);
	vec.x = x / size;
	vec.y = y / size;
	vec.z = z / size;
	return (vec);
}

t_vec			get_normale(t_pix *pix, t_point inter)
{
	if (pix->cur_obj->type == SPHERE)
		return (norm_maping(pix, inter, normalize(make_vec(inter, pix->cur_obj->coord))));
	else if (pix->cur_obj->type == PLANE)
		return (norm_maping(pix, inter, ((t_plane *)pix->cur_obj)->norm));
	else if (pix->cur_obj->type == CYLINDER)
		return (norm_maping(pix, inter, cylinder_norm(pix, inter)));
	else if (pix->cur_obj->type == CONE)
		return (norm_maping(pix, inter, cone_norm(pix, inter)));
	else
		return (normalize(vector(((t_triangle *)pix->cur_obj)->v
		, ((t_triangle *)pix->cur_obj)->u)));
}
