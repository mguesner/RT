/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precalc_vec_cam.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 14:32:16 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/30 13:43:56 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdlib.h>
#include <vecteur.h>
#include <stdio.h>

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
	((dir_vect_x.x / (double)WIDTH) * posx)
		+ ((dir_vect_y.x / (double)HEIGHT) * posy);
	current_pix.y = cam->pix_hg.y +
	((dir_vect_x.y / (double)WIDTH) * posx)
		+ ((dir_vect_y.y / (double)HEIGHT) * posy);
	current_pix.z = cam->pix_hg.z +
	((dir_vect_x.z / (double)WIDTH) * posx)
		+ ((dir_vect_y.z / (double)HEIGHT) * posy);
	return (current_pix);
}

t_pix			**precalc_vec_cam(t_camera *cam)
{
	int			pix_x;
	int			pix_y;
	t_pix		**vec_tab;
	t_point		pos_pix;
	t_vec		test;

	vec_tab = (t_pix **)malloc(sizeof(t_pix *) * TOTAL_PIX);
	pix_y = 0;
	while (pix_y < HEIGHT)
	{
		pix_x = 0;
		while (pix_x < WIDTH)
		{
			vec_tab[pix_x + pix_y * WIDTH] = malloc(sizeof(t_pix));
			vec_tab[pix_x + pix_y * WIDTH]->color = malloc(sizeof(t_color));
			vec_tab[pix_x + pix_y
				* WIDTH]->color_specular = malloc(sizeof(t_color));
			pos_pix = calc_pos_pix(cam, pix_x, pix_y);
			test = (make_vec(pos_pix, cam->coord));
			vec_tab[pix_x + pix_y * WIDTH]->pos_pix_vec = normalize(test);
			pix_x++;
		}
		pix_y++;
	}
	return (vec_tab);
}
