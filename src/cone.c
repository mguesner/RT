/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 16:17:32 by aleung-c          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/06/01 11:03:02 by mguesner         ###   ########.fr       */
=======
/*   Updated: 2015/05/31 17:02:17 by mguesner         ###   ########.fr       */
>>>>>>> 7cd3b65f04372d66d37274a6a935dfe3ef13abea
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
	return (ret2 > EPSILON ? ret2 : ret);
}

double	dist_cone2(t_cone *cone, t_vec vec, t_point o)
{
	double	a;
	double	b;
	double	c;
	double	det;

<<<<<<< HEAD
	a = pow(vec.x, 2) + pow(vec.y, 2) - pow(tan(cone->angle), 2) * pow(vec.z, 2);
	b = 2.0 * (vec.x * (o.x - cone->coord.x) + vec.y * (o.y - cone->coord.y)
			- vec.z * (o.z - cone->coord.z) * pow(tan(cone->angle), 2));
	c = pow((o.x - cone->coord.x), 2) + pow((o.y - cone->coord.y), 2)
		- pow(((o.z - cone->coord.z)), 2) * pow(tan(cone->angle), 2);
=======
	a = pow(vec.x, 2) + pow(vec.y, 2) - pow(tan(cone->angle / 2), 2) * pow(vec.z, 2);
	b = 2.0 * (vec.x * (o.x - cone->coord.x) + vec.y * (o.y - cone->coord.y)
			- vec.z * (o.z - cone->coord.z) * pow(tan(cone->angle / 2), 2));
	c = pow((o.x - cone->coord.x), 2) + pow((o.y - cone->coord.y), 2)
		- pow(((o.z - cone->coord.z)), 2) * pow(tan(cone->angle / 2), 2);
>>>>>>> 7cd3b65f04372d66d37274a6a935dfe3ef13abea
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
	// printf("vec(%f, %f, %f)\n", vec.x, vec.y, vec.z);
	// printf("o(%f, %f, %f)\n", o.x, o.y, o.z);
	// vec = *(t_point *)v;
	// o = *ori;
	param[0] = pow(vec.x, 2) + pow(vec.y, 2) - pow(vec.z, 2) * pow(tan(cone->angle / 2), 2);
	// printf("a : %f + %f + %f * %f = %f\n", pow(vec.x, 2), pow(vec.y, 2), pow(vec.z, 2), pow(tan(cone->angle), 2), param[0]);
	param[1] = 2 * (vec.x * (o.x - cone->coord.x) + vec.y
		* (o.y - cone->coord.y)
<<<<<<< HEAD
			- vec.z * (o.z - cone->coord.z) * pow(tan(cone->angle), 2));
	param[2] = pow((o.x - cone->coord.x), 2) + pow((o.y - cone->coord.y), 2)
		- pow(((o.z - cone->coord.z)), 2) * pow(tan(cone->angle), 2);
=======
			- vec.z * (o.z - cone->coord.z) * pow(tan(cone->angle / 2), 2));
	// printf("b : 2 * (%f * (%f - %f) + %f * (%f - %f) - %f * (%f - %f) * %f) = %f\n", vec.x, o.x, cone->coord.x, vec.y, o.y, cone->coord.y, vec.z, o.z, cone->coord.z, pow(tan(cone->angle), 2), param[1]);
	param[2] = pow((o.x - cone->coord.x), 2) + pow((o.y - cone->coord.y), 2)
		- pow(((o.z - cone->coord.z)), 2) * pow(tan(cone->angle / 2), 2);
>>>>>>> 7cd3b65f04372d66d37274a6a935dfe3ef13abea
	det = pow(param[1], 2) - 4.0 * param[0] * param[2];
	if (det > EPSILON)
		return (dist_sphere3(det, param[0], param[1]));
	return (-1);
}
