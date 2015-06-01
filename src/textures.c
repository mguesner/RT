/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 10:42:10 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/01 17:10:46 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void			add_texture_color(t_pix *vec_dir, double u, double v)
{
	if ((int)u < (vec_dir->cur_obj->texture.width) && 
		(int)v < (vec_dir->cur_obj->texture.height))
	{
		vec_dir->color->b = vec_dir->cur_obj->texture.data[(int)u 
			* (vec_dir->cur_obj->texture.bpp / 8) + (int)v * vec_dir->cur_obj->texture.size_line];
		vec_dir->color->g = vec_dir->cur_obj->texture.data[((int)u 
			* (vec_dir->cur_obj->texture.bpp / 8) + (int)v * vec_dir->cur_obj->texture.size_line) + 1];
		vec_dir->color->r = vec_dir->cur_obj->texture.data[((int)u 
			* (vec_dir->cur_obj->texture.bpp / 8) + (int)v * vec_dir->cur_obj->texture.size_line) + 2];
		vec_dir->color->b = vec_dir->color->b < 0 ? 255 + vec_dir->color->b : vec_dir->color->b;
		vec_dir->color->r = vec_dir->color->r < 0 ? 255 + vec_dir->color->r : vec_dir->color->r;
		vec_dir->color->g = vec_dir->color->g < 0 ? 255 + vec_dir->color->g : vec_dir->color->g;
	}
}

static void		texture_plane(t_pix *vec_dir)
{
	double		u;
	double		v;

	vec_dir->normale = get_normale(vec_dir, vec_dir->inter);
	if (fabs(vec_dir->normale.x) != 0.0)
	{
		u = fabs(fmod(vec_dir->inter.y, (float)vec_dir->cur_obj->texture.width));
		v = fabs(fmod(vec_dir->inter.z, (float)vec_dir->cur_obj->texture.height));
	}
	else if (fabs(vec_dir->normale.y) != 0.0)
	{
		u = fabs(fmod(vec_dir->inter.x, (float)vec_dir->cur_obj->texture.width));
		v = fabs(fmod(vec_dir->inter.z, (float)vec_dir->cur_obj->texture.height));
	}
	else
	{
		u = fabs(fmod(vec_dir->inter.y, (float)vec_dir->cur_obj->texture.width));
		v = fabs(fmod(vec_dir->inter.x, (float)vec_dir->cur_obj->texture.height));
	}
	add_texture_color(vec_dir, u, v);
}

void			texture_func(t_pix *vec_dir)
{
	double		u;
	double		v;
	t_vec		normale;

	if (vec_dir->cur_obj->type == SPHERE)
	{
		normale = normalize(make_vec(vec_dir->inter, vec_dir->cur_obj->coord));
		u = 0.5 - (atan2((-normale.z), (-normale.x)) / (2.0 * M_PI));
		v = 0.5 - 2.0 * (asin((normale.y)) / (2.0 * M_PI));
		u *= vec_dir->cur_obj->texture.width;
		v *= vec_dir->cur_obj->texture.height;
		add_texture_color(vec_dir, u, v);
	}
	else if (vec_dir->cur_obj->type == PLANE)
		texture_plane(vec_dir);
	else if (vec_dir->cur_obj->type == CYLINDER)
	{
		u = fabs(fmod(vec_dir->inter.y, (float)vec_dir->cur_obj->texture.width));
		v = fabs(fmod(vec_dir->inter.z, (float)vec_dir->cur_obj->texture.height));
		add_texture_color(vec_dir, u, v);
	}
	else if (vec_dir->cur_obj->type == CONE)
	{
		u = fabs(fmod(vec_dir->inter.y, (float)vec_dir->cur_obj->texture.width));
		v = fabs(fmod(vec_dir->inter.z, (float)vec_dir->cur_obj->texture.height));
		add_texture_color(vec_dir, u, v);
	}
}
