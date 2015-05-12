/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsourd-b <bsourd-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 11:20:04 by bsourd-b          #+#    #+#             */
/*   Updated: 2015/05/12 13:48:17 by bsourd-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

double	dist_cylinder(t_cylinder *cylinder, t_vec *vec, t_point *o)
{
	double	a;
	double	b;
	double	c;
	double	det;

	a= ;
	b= 2.0 * (v->x * (o->x - c->x) + );
	c=;
	det = pow(b, 2) - 4.0 * a * c;
	if (det > 0)
		return (-b + sqrt(det) / (2.0 * a));
	else
		return (-1);
}
