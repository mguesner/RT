/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 06:11:00 by matthieu          #+#    #+#             */
/*   Updated: 2015/05/16 06:23:12 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RT.h>

void	get_rotate(t_vec axe, double scalaire, double rot[3][3])
{
	double	cos;
	double	sin;
	double	ux;
	double	uy;
	double	uz;
	double	ux_2;
	double	uy_2;
	double	uz_2;

	cos = scalaire;
	sin = sqrt(1 - pow(cos, 2));
	axe = normalize(axe);
	ux = axe.x;
	uy = axe.y;
	uz = axe.z;
	ux_2 = pow(ux, 2);
	uy_2 = pow(uy, 2);
	uz_2 = pow(uz, 2);
	rot[0][0] = ux_2 + (1 - ux_2) * cos;
	rot[1][0] = ux * uy * (1 - cos) - uz * sin;
	rot[2][0] = ux * uz * (1 - cos) + uy * sin;
	rot[0][1] = ux * uy * (1 - cos) + uz * sin;
	rot[1][1] = uy_2 + (1 - uy_2) * cos;
	rot[2][1] = uy * uz * (1 - cos) - ux * sin;
	rot[0][2] = ux * uz * (1 - cos) - uy * sin;
	rot[1][2] = uy * uz * (1 - cos) + ux * sin;
	rot[2][2] = uz_2 + (1 - uz_2) * cos;
}