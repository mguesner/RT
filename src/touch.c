/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 10:32:06 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/12 10:47:20 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <vecteur.h>

double	touch(t_obj *obj, t_vec *vec, t_point *origine)
{
	if (obj->type == SPHERE)
		return (dist_sphere((t_sphere *)obj, vec, origine));
	else
		return (-1);
}
