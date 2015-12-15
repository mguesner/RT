/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 11:20:04 by bsourd-b          #+#    #+#             */
/*   Updated: 2015/06/02 14:02:54 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <matrice.h>

double	dist_cylinder3(double det, double a, double b)
{
	double	ret;
	double	ret2;

	ret = (-b + sqrt(det)) / (2.0 * a);
	ret2 = (-b - sqrt(det)) / (2.0 * a);
	return (ret2 > 0.0001 ? ret2 : ret);
}

double	dist_cylinder4(t_cylinder *cylinder, t_vec *v, t_point o)
{
	double	a;
	double	b;
	double	c;
	double	det;
	t_point	vec;

	vec = *(t_point *)v;
	a = pow(vec.x, 2) + pow(vec.y, 2);
	b = 2.0 * (vec.x * (o.x - cylinder->coord.x) + vec.y
		* (o.y - cylinder->coord.y));
	c = pow((o.x - cylinder->coord.x), 2) + pow((o.y - cylinder->coord.y)
		, 2) - pow(cylinder->radius, 2);
	det = pow(b, 2) - 4.0 * a * c;
	if (det > 0)
		return (dist_cylinder3(det, a, b));
	return (-1);
}

double	dist_cylinder2(t_cylinder *cylinder, t_vec *v, t_point o)
{
	double	a;
	double	b;
	double	c;
	double	dist;
	double	det;

	a = pow(v->x, 2) + pow(v->y, 2);
	b = 2.0 * (v->x * (o.x - cylinder->coord.x) + v->y
		* (o.y - cylinder->coord.y));
	c = pow((o.x - cylinder->coord.x), 2) + pow((o.y - cylinder->coord.y)
		, 2) - pow(cylinder->radius, 2);
	det = pow(b, 2) - 4.0 * a * c;
	if (det > 0)
	{
		dist = dist_cylinder3(det, a, b);
		return ((cylinder->limite1 == cylinder->limite2 || \
		(v->z * dist > cylinder->limite1 && v->z * \
		dist < cylinder->limite2)) ? dist : -1);
	}
	return (-1);
}

double	dist_cylinder(t_cylinder *cylinder, t_vec *v, t_point *ori)
{
	double	param[3];
	double	det;
	double	dist;
	t_point	vec;
	t_point	o;

	vec = do_rotate(cylinder->rot, *(t_point *)v);
	o = do_rotate(cylinder->rot, *ori);
	param[0] = pow(vec.x, 2) + pow(vec.y, 2);
	param[1] = 2.0 * (vec.x * (o.x - cylinder->coord.x)
		+ vec.y * (o.y - cylinder->coord.y));
	param[2] = pow((o.x - cylinder->coord.x), 2)
	+ pow((o.y - cylinder->coord.y), 2) - pow(cylinder->radius, 2);
	det = pow(param[1], 2) - 4.0 * param[0] * param[2];
	if (det > 0)
	{
		dist = dist_cylinder3(det, param[0], param[1]);
		return ((cylinder->limite1 == cylinder->limite2 || \
		(vec.z * dist > cylinder->limite1 && vec.z * \
		dist < cylinder->limite2)) ? dist : -1);
	}
	return (-1);
}
