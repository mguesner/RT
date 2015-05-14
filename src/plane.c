/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 11:07:35 by bsourd-b          #+#    #+#             */
/*   Updated: 2015/05/12 16:08:12 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>

double dist_plane(t_plane *plane, t_vec *vec, t_point *o)
{
	double	t;

	t = -(((plane->norm.x * o->x) + (plane->norm.y * o->y)
		+ (plane->norm.z * o->z) + plane->coord.z)
		  / ((plane->norm.x * vec->x) + (plane->norm.y * vec->y)
		+ (plane->norm.z * vec->z)));
	return (t);
}
