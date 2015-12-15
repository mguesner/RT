/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 10:32:06 by eruffieu          #+#    #+#             */
/*   Updated: 2015/06/03 15:46:51 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <vecteur.h>

double	touch(t_obj *obj, t_vec *vec, t_point *origine)
{
	if (obj->type == SPHERE)
		return (dist_sphere((t_sphere *)obj, vec, origine));
	else if (obj->type == PLANE)
		return (dist_plane((t_plane *)obj, vec, origine));
	else if (obj->type == CONE)
		return (dist_cone((t_cone *)obj, vec, origine));
	else if (obj->type == CYLINDER)
		return (dist_cylinder((t_cylinder *)obj, vec, origine));
	else if (obj->type == TRIANGLE)
		return (dist_triangle((t_triangle *)obj, vec, origine));
	else
		return (-1);
}

double	touch2(t_obj *obj, t_vec vec, t_point origine)
{
	if (obj->type == SPHERE)
		return (dist_sphere((t_sphere *)obj, &vec, &origine));
	else if (obj->type == PLANE)
		return (dist_plane((t_plane *)obj, &vec, &origine));
	else if (obj->type == CONE)
		return (dist_cone2((t_cone *)obj, vec, origine));
	else if (obj->type == CYLINDER)
		return (dist_cylinder2((t_cylinder *)obj, &vec, origine));
	else if (obj->type == TRIANGLE)
		return (dist_triangle((t_triangle *)obj, &vec, &origine));
	else
		return (-1);
}

double	touch4(t_obj *obj, t_vec vec, t_point origine)
{
	if (obj->type == SPHERE)
		return (dist_sphere((t_sphere *)obj, &vec, &origine));
	else if (obj->type == PLANE)
		return (dist_plane((t_plane *)obj, &vec, &origine));
	else if (obj->type == CONE)
		return (dist_cone2((t_cone *)obj, vec, origine));
	else if (obj->type == CYLINDER)
		return (dist_cylinder4((t_cylinder *)obj, &vec, origine));
	else
		return (-1);
}
