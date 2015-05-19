/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 10:42:10 by aleung-c          #+#    #+#             */
/*   Updated: 2015/05/19 13:04:15 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>

void	texture_func(t_libx *mlx, t_pix *vec_dir, char *texture, int width, int height,
						int bpp, int size_line) // norme a faire.
{
	t_point		inter_point;
	t_vec		normale;
	float		u;
	float		v;


	if (vec_dir->cur_obj == NULL)
		return ;
	inter_point = translate(mlx->cam->coord,
							vec_coef(vec_dir->pos_pix_vec, vec_dir->dist));
	if (vec_dir->cur_obj->type == SPHERE)
	{
		normale = normalize(make_vec(inter_point, vec_dir->cur_obj->coord));
		u = 0.5 + (atan2((-normale.x), (-normale.z)) / M_PI);
		v = 0.5 - asin((normale.y)) / M_PI;
		vec_dir->color->b = texture[(int)(u * width) * bpp +
		(int)(v * height) * size_line];
		vec_dir->color->g = texture[(int)(u * width) * bpp +
			(int)(v * height) * size_line + 1];
		vec_dir->color->r = texture[(int)(u * width) * bpp +
			(int)(v * height) * size_line + 2];
		// set_color(mlx, vec_dir);
	}
}
