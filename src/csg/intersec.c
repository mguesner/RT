/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsourd-b <bsourd-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 12:28:36 by bsourd-b          #+#    #+#             */
/*   Updated: 2015/05/13 12:38:58 by bsourd-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

double	dist_intersec (t_obj *obj1, t_obj *obj2, t_vec *vec, t_point *o)
{
	double	dist1;
	double	dist2;

	dist1 = touch(obj1, vec, o);
	dist2 = touch(obj2, vec, o);

	if (dist1 > 0 && dist 2 > 0)
	{
		if (dist1 < dist2)
			return (dist1);
		return (dist2);
	}
	return (-1);
}
				
