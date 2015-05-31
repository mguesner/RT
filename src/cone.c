/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 16:17:32 by aleung-c          #+#    #+#             */
/*   Updated: 2015/05/30 18:32:29 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>
#include <matrice.h>

double	dist_sphere3(double det, double a, double b)
{
	double	ret;
	double	ret2;

	ret = (-b + sqrt(det)) / (2.0 * a);
	ret2 = (-b - sqrt(det)) / (2.0 * a);
	return (ret2 > 0.0001 ? ret2 : ret);
}

double	dist_cone2(t_cone *cone, t_vec vec, t_point o)
{
	double	a;
	double	b;
	double	c;
	double	det;

	a = pow(vec.x, 2) + pow(vec.y, 2) - cone->angle * pow(vec.z, 2);
	b = 2.0 * (vec.x * (o.x - cone->coord.x) + vec.y * (o.y - cone->coord.y)
			- vec.z * (o.z - cone->coord.z) * cone->angle);
	c = (pow((o.x - cone->coord.x), 2) + pow((o.y - cone->coord.y), 2)
		- pow(((o.z - cone->coord.z)), 2)) * cone->angle;
	det = pow(b, 2) - 4.0 * a * c;
	if (det > EPSILON)
		return (dist_sphere3(det, a, b));
	return (-1);
}

double	dist_cone(t_cone *cone, t_vec *v, t_point *ori)
{
	double	param[3];
	double	det;
	t_point	vec;
	t_point	o;

	// printf("angle : %f, tan(angle) = %f, tan(angle)^2 = %f\n", cone->angle, tan(cone->angle), powf(tan(cone->angle), 2));
	vec = do_rotate(cone->rot, *(t_point *)v);
	o = do_rotate(cone->rot, *ori);
	// vec = *(t_point *)v;
	// o = *ori;
	param[0] = pow(vec.x, 2) + pow(vec.y, 2) - pow(vec.z, 2) * pow(tan(cone->angle), 2);
	param[1] = 2 * (vec.x * (o.x - cone->coord.x) + vec.y
		* (o.y - cone->coord.y)
			- vec.z * (o.z - cone->coord.z) * pow(tan(cone->angle), 2));
	param[2] = (pow((o.x - cone->coord.x), 2) + pow((o.y - cone->coord.y), 2)
		- pow(((o.z - cone->coord.z)), 2)) * pow(tan(cone->angle), 2);
	det = pow(param[1], 2) - 4.0 * param[0] * param[2];
	if (det > EPSILON)
		return (dist_sphere3(det, param[0], param[1]));
	return (-1);
}
