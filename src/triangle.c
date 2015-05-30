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

//	printf("%f %f %f\n", triangle->coord.x, triangle->coord.y, triangle->coord.z);
	normale = normalize(vector(triangle->u, triangle->v));
	d = -scalar(normale, *vec);
	if (d < 0.0001 && d >  -0.0001)
		return (-1.0);
	w = normalize(make_vec(*o, triangle->coord));
	a = -scalar(normalize(vector(w, triangle->v)), *vec) / d;
	b = -scalar(normalize(vector(triangle->u, w)), *vec) / d;
//	printf("d : %f, a : %f, b : %f\n", d, a, b);
	if (a > 0.0001 && b > 0.0001 && (a + b) <= 1.0)
		return (scalar(normale, w) / d);
	return (-1);
}

double	dist_triangle2(t_triangle *tr, t_vec *vec, t_point *o)
{
	t_vec n = normalize(vector(tr->u, tr->v)); // normale

	t_vec w = normalize(make_vec(*o, tr->coord));

	double a = -scalar(n, w);
	double b = scalar (n, *vec);
	if (fabs(b) < 0.0001)
	{
		if (a < 0.0001 && a >  -0.0001)
			return (-1); // ???
		else
			return (-1);
	}

	double r = a / b;
	if (r < 0.001)
		return (-1);

	t_point i;
	i.x = (*o).x + (r * (*vec).x);
	i.y = (*o).y + (r * (*vec).y);
	i.z = (*o).z + (r * (*vec).z);

	double uu = scalar(normalize(tr->u), normalize(tr->u));
	double uv = scalar(normalize(tr->u), normalize(tr->v));
	double vv = scalar(normalize(tr->v), normalize(tr->v));
	w = normalize(make_vec(i, tr->coord));
	double wu = scalar(w, normalize(tr->u));
	double wv = scalar(w, normalize(tr->v));
	double d = uv * uv - uu * vv;

	double s = (uv * wv - vv * wu) / d;
	if (s < 0.0 || s > 1.0)
        return 0;
	double t = (uv * wu - uu * wv) / d;
    if (t < 0.0 || (s + t) > 1.0)  // I is outside T
        return 0;

    return (r);
}