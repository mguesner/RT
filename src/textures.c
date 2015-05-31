/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 10:42:10 by aleung-c          #+#    #+#             */
/*   Updated: 2015/05/30 18:19:35 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>
#include <stdlib.h>

static void add_texture_color(t_pix *vec_dir, double u, double v)
{
	vec_dir->color->b = (int)vec_dir->cur_obj->texture.data[
						(int)u * vec_dir->cur_obj->texture.bpp
						+ (int)v * vec_dir->cur_obj->texture.size_line];
	vec_dir->color->g = (int)vec_dir->cur_obj->texture.data[
						((int)u * vec_dir->cur_obj->texture.bpp
						+ (int)v * vec_dir->cur_obj->texture.size_line) + 1];
	vec_dir->color->r = (int)vec_dir->cur_obj->texture.data[
						((int)u * vec_dir->cur_obj->texture.bpp
						+ (int)v * vec_dir->cur_obj->texture.size_line) + 2];
	vec_dir->color->b = vec_dir->color->b < 0 ?
			255 + vec_dir->color->b : vec_dir->color->b;
	vec_dir->color->r = vec_dir->color->r < 0 ?
			255 + vec_dir->color->r : vec_dir->color->r;
	vec_dir->color->g = vec_dir->color->g < 0 ?
			255 + vec_dir->color->g : vec_dir->color->g;
}

void	texture_func(t_pix *vec_dir)
{
	t_vec		normale;
	double		u;
	double		v;

	if (vec_dir->cur_obj->type == SPHERE)
	{
		normale = normalize(make_vec(vec_dir->inter, vec_dir->cur_obj->coord));
		u = 0.5 - (atan2((-normale.z), (-normale.x)) / (M_PI * 5.0));
		v = 0.5 - 2.0 * (asin((normale.y)) / (M_PI * 2.0));
		u *= vec_dir->cur_obj->texture.width;
		v *= vec_dir->cur_obj->texture.height;
		add_texture_color(vec_dir, u, v);
	}
	else if (vec_dir->cur_obj->type == PLANE) // Pour chaque type de plan.
	{
		if (fabs(vec_dir->inter.x) > 998.0 && fabs(vec_dir->inter.x) < 1001.0)
		{
			u = fabs(fmod(vec_dir->inter.y / 6.0, (float)vec_dir->cur_obj->texture.width));
			v = fabs(fmod(vec_dir->inter.z, (float)vec_dir->cur_obj->texture.height - 4.0));
		}
		else if (fabs(vec_dir->inter.y) > 9998.0 && fabs(vec_dir->inter.y) < 10001.0)
		{
			u = fabs(fmod(vec_dir->inter.z / 6.0, (float)vec_dir->cur_obj->texture.width));
			v = fabs(fmod(vec_dir->inter.x, (float)vec_dir->cur_obj->texture.height - 8.0));
		}
		else
		{
			u = fabs(fmod(vec_dir->inter.x / 6.0, (float)vec_dir->cur_obj->texture.width));
			v = fabs(fmod(vec_dir->inter.y, (float)vec_dir->cur_obj->texture.height - 4.0));
		}
		if ((int)u < vec_dir->cur_obj->texture.width && (int)v < vec_dir->cur_obj->texture.height)
			add_texture_color(vec_dir, u, v);
	}
	// else if (vec_dir->cur_obj->type == CYLINDER) // A FAIRE
	// {
	// 	u = fabs(fmod(vec_dir->inter.y, (float)vec_dir->cur_obj->texture.width));
	// 	v = fabs(fmod(vec_dir->inter.z, (float)vec_dir->cur_obj->texture.height - 8.0));
	// 	add_texture_color(vec_dir, u, v);
	// }
}
