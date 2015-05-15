/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 13:34:42 by aleung-c          #+#    #+#             */
/*   Updated: 2015/05/15 10:24:19 by aleung-c         ###   ########.fr       */
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
	t_vec		intp_cam;
	t_vec 
	double		dot;
	double		angle;

	// d'abord, check si obj est reflectif.
	if (pix->cur_obj->reflect == 1) // var reflect a rajouter dans le h.
	{
		// pour faire la reflexion, trouver le point d'intersection avec l'obj.
		inter_point = intersection_point(dist, pix->pos_pix_vec);

		// trouver le vecteur du pt d'inter et de la cam.
		intp_cam = make_vec(inter_point, mlx->cam->coord);
		// puis, trouver la normale de l'objet touché.
		normale = find_normal_obj(inter_point, pix->cur_obj->type)


		// faire multiplication des vecteurs pour trouveur l'angle entre eux.
		dot = scalar(intp_cam, normale);
		angle = acos(dot); // angle de rotation a effectuer.
		// faire rotation de la normale avec l'angle trouvé;

		// avec ce vecteur, check pour chaque obj si touch =>  recursive debut de RT.

	}
	else
		return ;
}