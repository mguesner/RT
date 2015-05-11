/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 15:47:03 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/11 16:11:15 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <vecteur.h>

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
