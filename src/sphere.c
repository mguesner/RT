/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 15:47:03 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/14 13:40:35 by bsourd-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <math.h>
#include <stdio.h>

double	dist_sphere(t_sphere *sphere, t_vec *vec, t_point *o)
{
	double	a;
	double	b;
	double	c;
	double	det;

	a = pow(vec->x, 2) + pow(vec->y, 2)  + pow(vec->z, 2);
	b = 2.0 * vec->x * (o->x - sphere->coord.x) +  2.0 *
		vec->y * (o->y - sphere->coord.y) + 2.0 *
		vec->z * (o->z - sphere->coord.z);
	c = pow(sphere->coord.x, 2) + pow(sphere->coord.y, 2) +
		pow(sphere->coord.z, 2) + pow(o->x, 2) + pow(o->y, 2) +
		pow(o->z, 2) + -2.0 * (sphere->coord.x * o->x +
			sphere->coord.y * o->y + sphere->coord.z * o->z) -
		pow(sphere->radius, 2);
	det = pow(b, 2) - 4.0 * a * c;
	if (det > 0)
	{
		double ret = (-(b) + sqrt(det)) / 2.0 * a;
		double ret2 = (-(b) - sqrt(det)) / 2.0 * a;
		return (ret2 > 0.0001 ? ret2 : ret);
	}
	return (-1);
}
