/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 16:17:32 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/03 15:43:46 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
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
	double	dist;
	double	det;

	a = pow(vec.x, 2) + pow(vec.y, 2) - pow(tan(cone->angle), 2)
	* pow(vec.z, 2);
	b = 2.0 * (vec.x * (o.x - cone->coord.x) + vec.y * (o.y - cone->coord.y)
			- vec.z * (o.z - cone->coord.z) * pow(tan(cone->angle), 2));
	c = pow((o.x - cone->coord.x), 2) + pow((o.y - cone->coord.y), 2)
		- pow(((o.z - cone->coord.z)), 2) * pow(tan(cone->angle), 2);
	det = pow(b, 2) - 4.0 * a * c;
	if (det > EPSILON)
	{
		dist = dist_sphere3(det, a, b);
		return ((cone->limite1 == cone->limite2 || \
		(vec.z * dist > cone->limite1 && \
		vec.z * dist < cone->limite2)) ? dist : -1);
	}
	return (-1);
}

double	dist_cone(t_cone *cone, t_vec *v, t_point *ori)
{
	double	param[3];
	double	det;
	t_point	vec;
	double	dist;
	t_point	o;

	vec = do_rotate(cone->rot, *(t_point *)v);
	o = do_rotate(cone->rot, *ori);
	param[0] = pow(vec.x, 2) + pow(vec.y, 2) - pow(vec.z, 2)
	* pow(tan(cone->angle), 2);
	param[1] = 2 * (vec.x * (o.x - cone->coord.x) + vec.y
		* (o.y - cone->coord.y)
			- vec.z * (o.z - cone->coord.z) * pow(tan(cone->angle), 2));
	param[2] = pow((o.x - cone->coord.x), 2) + pow((o.y - cone->coord.y), 2)
		- pow(((o.z - cone->coord.z)), 2) * pow(tan(cone->angle), 2);
	det = pow(param[1], 2) - 4.0 * param[0] * param[2];
	if (det > EPSILON)
	{
		dist = dist_sphere3(det, param[0], param[1]);
		return ((cone->limite1 == cone->limite2 || \
		(vec.z * dist > cone->limite1 && vec.z * \
		dist < cone->limite2)) ? dist : -1);
	}
	return (-1);
}
