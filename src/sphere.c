/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 15:47:03 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/12 10:40:39 by bsourd-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

double	dist_sphere(t_sphere *sphere, t_vec *vec, t_point *o)
{
	double	a;
	double	b;
	double	c;
	double	det;

	a = pow(vec->x, 2) + pow(vec->y, 2)  + pow(vec->z, 2);
	b = 2.0 * (vec->x * (o->x - sphere->x) + vec->y * (o->y - sphere->y)
			+ vec->z * (o->z - sphere->z));
	c = (pow((o->x - sphere->x), 2) + pow((o->y - sphere->y), 2)
		+ pow(((o->z - sphere->z)), 2)) - pow(sphere->radius, 2);
	det = pow(b, 2) - 4.0 * a * c;
	if (det > 0)
		return (-b + sqrt(det) / (2.0 * a));
	else
		return (-1);
}


/*
double	dist_sphere(t_libx *mlx, int pix_x, int pix_y)
{




	return (-((mlx->obj->begin->obj->coord.x * 10.0
		+ mlx->obj->begin->obj->coord.y * 10.0 +
		mlx->obj->begin->obj->coord.z * 10.0 +
		1.0) /
		(mlx->obj->begin->obj->coord.x * mlx->pos_all_pix[pix_x + pix_y * WIDTH].x +
		mlx->obj->begin->obj->coord.y * mlx->pos_all_pix[pix_x + pix_y * WIDTH].y +
		mlx->obj->begin->obj->coord.z * mlx->pos_all_pix[pix_x + pix_y * WIDTH].z)));
}
*/
