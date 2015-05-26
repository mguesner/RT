/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 06:23:50 by matthieu          #+#    #+#             */
/*   Updated: 2015/05/26 14:11:01 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_point	do_rotate(double rot[3][3], t_point p)
{
	t_point	ret;
	double	x;
	double	y;
	double	z;

	x = p.x;
	y = p.y;
	z = p.z;
	ret.x = x * rot[0][0] + y * rot[0][1] + z * rot[0][2];
	ret.y = x * rot[1][0] + y * rot[1][1] + z * rot[1][2];
	ret.z = x * rot[2][0] + y * rot[2][1] + z * rot[2][2];
	return (ret);
}
