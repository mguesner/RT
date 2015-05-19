/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 11:20:04 by bsourd-b          #+#    #+#             */
/*   Updated: 2015/05/19 15:55:13 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <matrice.h>

double	dist_cylinder(t_cylinder *cylinder, t_vec *v, t_point *ori)
{
	double	a;
	double	b;
	double	c;
	double	det;
	t_point	vec;
	t_point	o;

	vec = do_rotate(cylinder->rot, *(t_point *)v);
	o = do_rotate(cylinder->rot, *ori);
	a = pow(vec.x, 2) + pow(vec.y, 2);
	b = 2.0 * (vec.x * (o.x - cylinder->coord.x) + vec.y * (o.y - cylinder->coord.y));
	c = pow((o.x - cylinder->coord.x), 2) + pow((o.y - cylinder->coord.y), 2) - pow(cylinder->radius, 2);;
	det = pow(b, 2) - 4.0 * a * c;
    if (det > 0)
    {
        double ret = (-b + sqrt(det)) / (2.0 * a);
        double ret2 = (-b - sqrt(det)) / (2.0 * a);
        return (ret2 > 0.0001 ? ret2 : ret);
    }
	else
		return (-1);
}
