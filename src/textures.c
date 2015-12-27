/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 10:42:10 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/02 15:52:46 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void		add_texture_color(t_pix *vec_dir, double u, double v)
{
	int	x;
	int y;

	u  += vec_dir->cur_obj->surf.offset.x;
	u = u > vec_dir->cur_obj->surf.texture.width ?
		u - vec_dir->cur_obj->surf.texture.width : u;
	v  += vec_dir->cur_obj->surf.offset.y;
	v = v > vec_dir->cur_obj->surf.texture.height ?
		v - vec_dir->cur_obj->surf.texture.width : v;
	x = (int)u * (vec_dir->cur_obj->surf.texture.bpp / 8);
	y = (int)v * vec_dir->cur_obj->surf.texture.size_line;

	if ((int)u < (vec_dir->cur_obj->surf.texture.width) &&
		(int)v < (vec_dir->cur_obj->surf.texture.height))
	{
		vec_dir->color->b = vec_dir->cur_obj->surf.texture.data[x + y];
		vec_dir->color->g = vec_dir->cur_obj->surf.texture.data[x + y + 1];
		vec_dir->color->r = vec_dir->cur_obj->surf.texture.data[x + y + 2];
		vec_dir->color->b = vec_dir->color->b < 0 ?
			255 + vec_dir->color->b : vec_dir->color->b;
		vec_dir->color->r = vec_dir->color->r < 0 ?
			255 + vec_dir->color->r : vec_dir->color->r;
		vec_dir->color->g = vec_dir->color->g < 0 ?
			255 + vec_dir->color->g : vec_dir->color->g;
	}
}

static void		texture_plane(t_pix *vec_dir, double u, double v)
{
	vec_dir->normale = get_normale(vec_dir, vec_dir->inter);
	if (fabs(vec_dir->normale.x) != 0.0)
	{
		u = fabs(fmod(vec_dir->inter.y,
			(float)vec_dir->cur_obj->surf.texture.width));
		v = fabs(fmod(vec_dir->inter.z,
			(float)vec_dir->cur_obj->surf.texture.height));
	}
	else if (fabs(vec_dir->normale.y) != 0.0)
	{
		u = fabs(fmod(vec_dir->inter.x,
			(float)vec_dir->cur_obj->surf.texture.width));
		v = fabs(fmod(vec_dir->inter.z,
			(float)vec_dir->cur_obj->surf.texture.height));
	}
	else
	{
		u = fabs(fmod(vec_dir->inter.y,
			(float)vec_dir->cur_obj->surf.texture.width));
		v = fabs(fmod(vec_dir->inter.x,
			(float)vec_dir->cur_obj->surf.texture.height));
	}
	add_texture_color(vec_dir, u, v);
}

static void		texture_sphere(t_pix *vec_dir, double u, double v)
{
	t_vec		normale;

	normale = normalize(make_vec(vec_dir->inter, vec_dir->cur_obj->coord));
	u = 0.5 - (atan2((-normale.x), (-normale.y)) / (2.0 * M_PI));
	v = 0.5 + 2.0 * (asin((normale.z)) / (2.0 * M_PI));
	u *= vec_dir->cur_obj->surf.texture.width;
	v *= vec_dir->cur_obj->surf.texture.height;
	add_texture_color(vec_dir, u, v);
}

void			texture_func(t_pix *vec_dir)
{
	double		u;
	double		v;

	u = 0.0;
	v = 0.0;
	if (vec_dir->cur_obj->type == SPHERE)
		texture_sphere(vec_dir, u, v);
	else if (vec_dir->cur_obj->type == PLANE)
		texture_plane(vec_dir, u, v);
	else if (vec_dir->cur_obj->type == CYLINDER)
	{
		u = fabs(fmod(vec_dir->inter.y,
			(float)vec_dir->cur_obj->surf.texture.width));
		v = fabs(fmod(vec_dir->inter.z,
			(float)vec_dir->cur_obj->surf.texture.height));
		add_texture_color(vec_dir, u, v);
	}
	else if (vec_dir->cur_obj->type == CONE)
	{
		u = fabs(fmod(vec_dir->inter.y,
			(float)vec_dir->cur_obj->surf.texture.width));
		v = fabs(fmod(vec_dir->inter.z,
			(float)vec_dir->cur_obj->surf.texture.height));
		add_texture_color(vec_dir, u, v);
	}
}
