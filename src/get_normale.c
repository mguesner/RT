/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/18 14:34:10 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/18 17:54:58 by eruffieu         ###   ########.fr       */
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
    float x;
    float y;
    float z;
    float size;
    // float dot;
    t_vec	vec;

    x = inter.x - pix->cur_obj->coord.x;
    y = inter.y - pix->cur_obj->coord.y;
    z = -pix->cur_obj->coord.z * (inter.z - pix->cur_obj->coord.y);
    size = sqrt(x * x + y * y + z * z);
    vec.x = x / size;
    vec.y = y / size;
    vec.z = z / size;
    // dot = vec.x * pix->vec_dir.x + vec.y * pix->vec_dir.y
    // + vec.z * pix->vec_dir.z;
    // x = 2 * dot * vec.x;
    // y = 2 * dot * vec.y;
    // z = 2 * dot * vec.z;
    // e->reflect_ray.x = pix->vec_dir.x - x;
    // e->reflect_ray.y = pix->vec_dir.y - y;
    // e->reflect_ray.z = pix->vec_dir.z - z;
    // ft_rot_reflect(e);
    return (vec);
}

t_vec	get_normale(t_pix *pix, t_point inter)
{
	if (pix->cur_obj->type == SPHERE)
		return (normalize(make_vec(inter, pix->cur_obj->coord)));
	else if (pix->cur_obj->type == PLANE)
	{

		return (*((t_vec *)&(pix->cur_obj->coord)));
	}
	else if (pix->cur_obj->type == CYLINDER)
		return(cylinder_norm(pix, inter));
	else
		return (cone_norm(pix, inter));
}

