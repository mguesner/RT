/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 15:47:03 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/13 14:38:14 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>

double	dist_sphere(t_sphere *sphere, t_vec *vec, t_point *o)
{
	double	a;
	double	b;
	double	c;
	double	det;

	a = pow(vec->x, 2) + pow(vec->y, 2)  + pow(vec->z, 2);
	b = 2.0 * (vec->x * (o->x - sphere->coord.x) + vec->y * (o->y - sphere->coord.y)
			+ vec->z * (o->z - sphere->coord.z));
	c = (pow((o->x - sphere->coord.x), 2) + pow((o->y - sphere->coord.y), 2)
		+ pow(((o->z - sphere->coord.z)), 2)) - pow(sphere->radius, 2);
	det = pow(b, 2) - 4.0 * a * c;
	if (det > 0)
		return (-b + sqrt(det) / (2.0 * a));
	return (-1);
}
