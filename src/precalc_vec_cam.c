/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precalc_vec_cam.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 14:32:16 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/11 15:06:07 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdlib.h>
#include <vecteur.h>

static t_point	calc_pos_pix(t_camera *cam, int posx, int posy)
{
	t_point	dir_vect_y;
	t_point	dir_vect_x;
	t_point	current_pix;

	dir_vect_y.x = cam->pix_bg.x - cam->pix_hg.x;
	dir_vect_y.y = cam->pix_bg.y - cam->pix_hg.y;
	dir_vect_y.z = cam->pix_bg.z - cam->pix_hg.z;
	dir_vect_x.x = cam->pix_hd.x - cam->pix_hg.x;
	dir_vect_x.y = cam->pix_hd.y - cam->pix_hg.y;
	dir_vect_x.z = cam->pix_hd.z - cam->pix_hg.z;
	current_pix.x = cam->pix_hg.x +
	((dir_vect_x.x / (double)WIDTH) * posx) + ((dir_vect_y.x / (double)HEIGHT) * posy);
	current_pix.y = cam->pix_hg.y +
	((dir_vect_x.y / (double)WIDTH) * posx) + ((dir_vect_y.y / (double)HEIGHT) * posy);
	current_pix.z = cam->pix_hg.z +
	((dir_vect_x.z / (double)WIDTH) * posx) + ((dir_vect_y.z / (double)HEIGHT) * posy);
	return (current_pix);
}

t_vec			*precalc_vec_cam(t_camera *cam)
{
	int		pix_x;
	int		pix_y;
	t_vec	*vec_tab;
	t_point	pos_pix;

	vec_tab = (t_vec *)malloc(TOTAL_PIX * sizeof(t_vec));
	pix_y = 0;
	while (pix_y < 1000)
	{
		pix_x = 0;
		while (pix_x < 1000)
		{
			pos_pix = calc_pos_pix(cam, pix_x, pix_y);
			vec_tab[pix_x + pix_y * WIDTH] = normalize((make_vec(cam->coord, pos_pix)));
			pix_x++;
		}
		pix_y++;
	}
	return (vec_tab);
}
