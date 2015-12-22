/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 06:11:00 by matthieu          #+#    #+#             */
/*   Updated: 2015/05/26 15:16:39 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#define RAD(x) ((x / 180.0) * M_PI)

void	get_rotate(t_vec axe, double cos, double rot[3][3])
{
	double	sin;

	sin = sqrt(1 - pow(cos, 2));
	axe = normalize(axe);
	rot[0][0] = pow(axe.x, 2) + (1 - pow(axe.x, 2)) * cos;
	rot[1][0] = axe.x * axe.y * (1 - cos) - axe.z * sin;
	rot[2][0] = axe.x * axe.z * (1 - cos) + axe.y * sin;
	rot[0][1] = axe.x * axe.y * (1 - cos) + axe.z * sin;
	rot[1][1] = pow(axe.y, 2) + (1 - pow(axe.y, 2)) * cos;
	rot[2][1] = axe.y * axe.z * (1 - cos) - axe.x * sin;
	rot[0][2] = axe.x * axe.z * (1 - cos) - axe.y * sin;
	rot[1][2] = axe.y * axe.z * (1 - cos) + axe.x * sin;
	rot[2][2] = pow(axe.z, 2) + (1 - pow(axe.z, 2)) * cos;
}

void	get_rotate_angle(t_vec axe, double angle, double rot[3][3])
{
	double	v_cos;
	double	v_sin;

	v_cos = cos(RAD(angle));
	v_sin = sin(RAD(angle));
	axe = normalize(axe);
	rot[0][0] = pow(axe.x, 2) + (1 - pow(axe.x, 2)) * v_cos;
	rot[1][0] = axe.x * axe.y * (1 - v_cos) - axe.z * v_sin;
	rot[2][0] = axe.x * axe.z * (1 - v_cos) + axe.y * v_sin;
	rot[0][1] = axe.x * axe.y * (1 - v_cos) + axe.z * v_sin;
	rot[1][1] = pow(axe.y, 2) + (1 - pow(axe.y, 2)) * v_cos;
	rot[2][1] = axe.y * axe.z * (1 - v_cos) - axe.x * v_sin;
	rot[0][2] = axe.x * axe.z * (1 - v_cos) - axe.y * v_sin;
	rot[1][2] = axe.y * axe.z * (1 - v_cos) + axe.x * v_sin;
	rot[2][2] = pow(axe.z, 2) + (1 - pow(axe.z, 2)) * v_cos;
}
