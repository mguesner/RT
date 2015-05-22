/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 13:34:42 by aleung-c          #+#    #+#             */
/*   Updated: 2015/05/21 14:15:16 by eruffieu         ###   ########.fr       */
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

void reflection(t_libx *mlx, t_pix *pix)
{
	t_point		inter_point;
	t_vec		normale;
	t_vec		R1;
	double		dot;

	// d'abord, check si obj est reflectif.
	// if (pix->cur_obj->reflect == 1) // var reflect a rajouter dans le h.
	// {
		// pour faire la reflexion, trouver le point d'intersection avec l'obj.
		inter_point = translate(mlx->cam->coord,
		vec_coef(pix->pos_pix_vec, pix->dist));

		// trouver le vecteur du pt d'inter et de la cam.
		// intp_cam = make_vec(inter_point, mlx->cam->coord);
		// puis, trouver la normale de l'objet touché.
		normale = get_normale(pix, inter_point);
		// faire multiplication des vecteurs pour trouveur l'angle entre eux.
		dot = -(scalar(normale, pix->pos_pix_vec)); // angle de rotation a effectuer.
		// faire rotation de la normale avec l'angle trouvé;

		// avec ce vecteur, check pour chaque obj si touch =>  recursive debut de RT.
		return ;
}
