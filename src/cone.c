/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguezell <nguezell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 16:17:32 by aleung-c          #+#    #+#             */
/*   Updated: 2015/05/13 10:30:00 by nguezell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>

double	dist_cone(t_cone *cone, t_vec *vec, t_point *o)
{
	double	a;
	double	b;
	double	c;
	double	det;

	a = pow(vec->x, 2) + pow(vec->y, 2)  - cone->angle * pow(vec->z, 2);
	b = 2.0 * (vec->x * (o->x - cone->coord.x) + vec->y * (o->y - cone->coord.y)
			- vec->z * (o->z - cone->coord.z) * cone->angle);
	c = (pow((o->x - cone->coord.x), 2) + pow((o->y - cone->coord.y), 2)
		- pow(((o->z - cone->coord.z)), 2)) * cone->angle;
	det = pow(b, 2) - 4.0 * a * c;
	if (det > 0)
		return (-b + sqrt(det) / (2.0 * a));
	return (-1);
}