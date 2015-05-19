/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate_vec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 13:03:25 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/19 13:05:09 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_vec	do_rotate_vec(double rot[3][3], t_vec p)
{
	t_vec	ret;
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
