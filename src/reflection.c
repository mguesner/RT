/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 13:34:42 by aleung-c          #+#    #+#             */
/*   Updated: 2015/05/13 15:06:24 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>

t_vec find_normal_obj(t_point inter_point, 	t_obj *obj)
{
	t_vec normale;

	if (obj->type == SPHERE)
		normale = make_vec(obj->coord, inter_point);
	return (normale);
}

void reflection(t_libx *mlx, double dist, t_pix *pix)
{
	t_point		inter_point;
	t_vec		normale;

	// d'abord, check si obj est reflectif.
	if (pix->cur_obj->reflect == 1) // var reflect a rajouter dans le h.
	{
		// pour faire la reflexion, trouver le point d'intersection avec l'obj.
		inter_point = intersection_point(dist, pix->pos_pix_vec);

		// puis, trouver la normale de l'objet touché.
		normale = find_normal_obj(inter_point, pix->cur_obj->type)
		// avec l'angle qui separe la normale du vecteur de dir du pix,
		// trouver le vecteur de reflection. imaginer le ricochet d'une balle.

		// avec ce vecteur, check pour chaque obj si touch =>  recursive debut de RT.

	}
}