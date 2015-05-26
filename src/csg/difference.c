/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   difference.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 11:13:42 by bsourd-b          #+#    #+#             */
/*   Updated: 2015/05/26 15:21:10 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

double	dist_difference(t_obj *obj1, t_obj *obj2, t_vec *vec, t_point *o)
{
	double	dist1;
	double	dist2;

	dist1 = touch(obj1, vec, o);
	dist2 = touch(obj2, vec, o);
	if (dist2 > 0 || dist1 < 0)
		return (-1);
	return (dist1);
}
