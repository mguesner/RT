/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 06:11:00 by matthieu          #+#    #+#             */
/*   Updated: 2015/05/26 14:12:10 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RT.h>
#define RAD(x) ((x / 180.0) * M_PI)

void	get_rotate(t_vec axe, double cos, double rot[3][3])
{
	double	sin;
	double	ux;
	double	uy;
	double	uz;
	double	ux_2;
	double	uy_2;
	double	uz_2;

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

void	get_rotate_angle(t_vec axe, double angle, double rot[3][3])
{
	double	__cos;
	double	__sin;
	double	ux;
	double	uy;
	double	uz;
	double	ux_2;
	double	uy_2;
	double	uz_2;

	__cos = cos(RAD(angle));
	__sin = sin(RAD(angle));
	axe = normalize(axe);
	ux = axe.x;
	uy = axe.y;
	uz = axe.z;
	ux_2 = pow(ux, 2);
	uy_2 = pow(uy, 2);
	uz_2 = pow(uz, 2);
	rot[0][0] = ux_2 + (1 - ux_2) * __cos;
	rot[1][0] = ux * uy * (1 - __cos) - uz * __sin;
	rot[2][0] = ux * uz * (1 - __cos) + uy * __sin;
	rot[0][1] = ux * uy * (1 - __cos) + uz * __sin;
	rot[1][1] = uy_2 + (1 - uy_2) * __cos;
	rot[2][1] = uy * uz * (1 - __cos) - ux * __sin;
	rot[0][2] = ux * uz * (1 - __cos) - uy * __sin;
	rot[1][2] = uy * uz * (1 - __cos) + ux * __sin;
	rot[2][2] = uz_2 + (1 - uz_2) * __cos;
}
