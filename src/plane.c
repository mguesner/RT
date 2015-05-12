/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 11:07:35 by bsourd-b          #+#    #+#             */
/*   Updated: 2015/05/12 13:54:51 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>

double dist_plane(t_plane *plane, t_vec *vec, t_point *o)
{
	double	t;

	t = (((plane->coord.x * o->x) + (plane->coord.y * o->y)
		+ (plane->coord.z * o->z) + plane->d)
		/ ((plane->coord.x * vec->x) + (plane->coord.y * vec->y)
		+ (plane->coord.z * vec->z)));
	return (t);
}
