/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsourd-b <bsourd-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 16:20:26 by bsourd-b          #+#    #+#             */
/*   Updated: 2015/05/28 16:20:27 by bsourd-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

double	dist_triangle(t_triangle *triangle, t_vec *vec, t_point *o)
{
	t_vec	normale;
	double	d;
	t_vec	w;
	double	a;
	double	b;

	normale = normalize(vector(triangle->u, triangle->v));
	d = -scalar(normale, *vec);
	if (d < 0.0001 && d >  -0.0001)
		return (-1.0);
	w = make_vec(*o, triangle->coord);
	a = -scalar(vector(w, triangle->v), *vec) / d;
	b = -scalar(vector(triangle->u, w), *vec) / d;
	if (a > 0.0001 && b > 0.0001 && (a + b) <= 1.0)
		return (scalar(normale, w) / d);
	return (-1);
}