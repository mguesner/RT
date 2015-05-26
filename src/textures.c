/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 10:42:10 by aleung-c          #+#    #+#             */
/*   Updated: 2015/05/26 13:15:39 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>
#include <stdlib.h>

void	texture_func(t_pix *vec_dir)
{
	t_vec		normale;
	float		u;
	float		v;

	if (vec_dir->cur_obj->type == SPHERE)
	{
		normale = normalize(make_vec(vec_dir->inter, vec_dir->cur_obj->coord));
		u = 0.5 + (atan2((-normale.x), (-normale.z)) / M_PI);
		v = 0.5 - asin((normale.y)) / M_PI;
		vec_dir->color->b = vec_dir->cur_obj->texture.data[(int)(u * vec_dir->cur_obj->texture.width)
		* vec_dir->cur_obj->texture.bpp + (int)(v * vec_dir->cur_obj->texture.height)
		* vec_dir->cur_obj->texture.size_line];
		vec_dir->color->g = vec_dir->cur_obj->texture.data[(int)(u * vec_dir->cur_obj->texture.width)
		* vec_dir->cur_obj->texture.bpp + (int)(v * vec_dir->cur_obj->texture.height) *
		vec_dir->cur_obj->texture.size_line + 1];
		vec_dir->color->r = vec_dir->cur_obj->texture.data[(int)(u * vec_dir->cur_obj->texture.width)
		* vec_dir->cur_obj->texture.bpp + (int)(v * vec_dir->cur_obj->texture.height) *
		vec_dir->cur_obj->texture.size_line + 2];
		vec_dir->color->b = vec_dir->color->b < 0 ? 255 + vec_dir->color->b : vec_dir->color->b;
		vec_dir->color->r = vec_dir->color->r < 0 ? 255 + vec_dir->color->r : vec_dir->color->r;
		vec_dir->color->g = vec_dir->color->g < 0 ? 255 + vec_dir->color->g : vec_dir->color->g;
	}
}
