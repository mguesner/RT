/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsourd-b <bsourd-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 11:07:35 by bsourd-b          #+#    #+#             */
/*   Updated: 2015/05/12 11:17:19 by bsourd-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

double dist_plane(t_plane *plane, t_vec *vec, t_point *o)
{
	double	t;

	t = -(((plane->coord.x * o->x) + (plane->coord.y * o->y)
		+ (plane->coord.z * o->z) + plane->d)
		/ ((plane->coord.x * vec->x) + (plane->coord.y * vec->y)
		+ (plane->coord.z * vec->z)));
	return (t);
}
