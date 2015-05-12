/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 11:07:35 by bsourd-b          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/05/12 13:54:51 by eruffieu         ###   ########.fr       */
=======
/*   Updated: 2015/05/12 14:12:08 by bsourd-b         ###   ########.fr       */
>>>>>>> 6ddcc09a195c950b18a09512f2f0efeffc691407
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>

double dist_plane(t_plane *plane, t_vec *vec, t_point *o)
{
	double	t;

<<<<<<< HEAD
	t = (((plane->coord.x * o->x) + (plane->coord.y * o->y)
		+ (plane->coord.z * o->z) + plane->d)
		/ ((plane->coord.x * vec->x) + (plane->coord.y * vec->y)
		+ (plane->coord.z * vec->z)));
=======
	t = (((plane->norm.x * o->x) + (plane->norm.y * o->y)
		+ (plane->norm.z * o->z) + plane->coord->z)
		  / ((plane->norm.x * c->x) + (plane->norm.y * vec->y)
		+ (plane->norm.z * vec->z)));
>>>>>>> 6ddcc09a195c950b18a09512f2f0efeffc691407
	return (t);
}
