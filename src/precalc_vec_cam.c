/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precalc_vec_cam.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 14:32:16 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/31 15:11:55 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <rt.h>
#include <stdlib.h>
#include <vecteur.h>
#include <stdio.h>

static t_point	calc_pos_pix(t_camera *cam, int posx, int posy)
{
	t_point	current_pix;
	double	x_indent;
	double	y_indent;

	x_indent = VIEWPLANEWIDTH / (double)WIDTH;
	y_indent = VIEWPLANEHEIGHT / (double)HEIGHT;
	current_pix.x = cam->pix_hg.x + cam->right_vec.x * x_indent * (double)posx - cam->up_vec.x * y_indent * (double)posy;
	// printf("viewPlaneUpLeft(%f,%f,%f) + rightVec(%f,%f,%f)*xIndent(%f)*x(%f) - upVec(%f,%f,%f)*yIndent(%f)*y(%f) = "
	// 	, cam->pix_hg.x, cam->pix_hg.y, cam->pix_hg.z
	// 	, cam->right_vec.x, cam->right_vec.y, cam->right_vec.z
	// 	, x_indent, (double)posx
	// 	, cam->up_vec.x, cam->up_vec.y, cam->up_vec.z
	// 	, y_indent, (double)posy);
	current_pix.y = cam->pix_hg.y + cam->right_vec.y * x_indent * (double)posx - cam->up_vec.y * y_indent * (double)posy;

	current_pix.z = cam->pix_hg.z + cam->right_vec.z * x_indent * (double)posx - cam->up_vec.z * y_indent * (double)posy;
	// printf("(%f, %f, %f)\n", current_pix.x, current_pix.y, current_pix.z);
	return (current_pix);
}

t_pix			**precalc_vec_cam(t_camera *cam)
{
	int			pix_x;
	int			pix_y;
	t_pix		**vec_tab;
	t_point		pos_pix;
	t_vec		test;

	vec_tab = (t_pix **)malloc(TOTAL_PIX * sizeof(t_pix *));
	pix_y = 0;
	while (pix_y < HEIGHT)
	{
		pix_x = 0;
		while (pix_x < WIDTH)
		{
			vec_tab[pix_x + pix_y * WIDTH] = malloc(sizeof(t_pix));
			vec_tab[pix_x + pix_y * WIDTH]->color = malloc(sizeof(t_color));
			vec_tab[pix_x + pix_y * WIDTH]->color_specular = malloc(sizeof(t_color));
			pos_pix = calc_pos_pix(cam, pix_x, pix_y);
			test = (make_vec(pos_pix, cam->coord));
			vec_tab[pix_x + pix_y * WIDTH]->pos_pix_vec = normalize(test);
			pix_x++;
		}
		pix_y++;
	}
	return (vec_tab);
}
