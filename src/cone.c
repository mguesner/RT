/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 16:17:32 by aleung-c          #+#    #+#             */
/*   Updated: 2015/05/22 14:36:14 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>
#include <matrice.h>

double	dist_cone(t_cone *cone, t_vec *v, t_point *ori)
{
	double	a;
	double	b;
	double	c;
	double	det;
	t_point	vec;
	t_point	o;

	vec = do_rotate(cone->rot, *(t_point *)v);
	o = do_rotate(cone->rot, *ori);
	a = pow(vec.x, 2) + pow(vec.y, 2)  - cone->angle * pow(vec.z, 2);
	b = 2.0 * (vec.x * (o.x - cone->coord.x) + vec.y * (o.y - cone->coord.y)
			- vec.z * (o.z - cone->coord.z) * cone->angle);
	c = (pow((o.x - cone->coord.x), 2) + pow((o.y - cone->coord.y), 2)
		- pow(((o.z - cone->coord.z)), 2)) * cone->angle;
	det = pow(b, 2) - 4.0 * a * c;
	if (det > 0)
	{
		double ret = (-b + sqrt(det)) / (2.0 * a);
		double ret2 = (-b - sqrt(det)) / (2.0 * a);
		return (ret2 > 0.0001 ? ret2 : ret);
	}
	return (-1);
}
