/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 13:01:44 by bsourd-b          #+#    #+#             */
/*   Updated: 2015/05/26 15:21:12 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

double	dist_merge(t_obj *obj1, t_obj *obj2, t_vec *vec, t_point *o)
{
	double	dist1;
	double	dist2;

	dist1 = touch(obj1, vec, o);
	dist2 = touch(obj2, vec, o);
	if (dist1 > 0 && dist2 < 0)
		return (dist1);
	if (dist2 > 0 && dist1 < 0)
		return (dist2);
	return (-1);
}
