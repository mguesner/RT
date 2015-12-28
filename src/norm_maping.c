/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_maping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsourd-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 08:41:25 by bsourd-b          #+#    #+#             */
/*   Updated: 2015/12/21 08:41:30 by bsourd-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static t_vec		apply_map(t_pix *pic, t_vec norm, double u, double v)
{
	int				pos;
	double			d;
	unsigned char	tmp;

	pos = ((int)u * (pic->cur_obj->surf.mapping.bpp / 8)
		+ (int)v * pic->cur_obj->surf.mapping.size_line);
	tmp = (unsigned char)pic->cur_obj->surf.mapping.data[pos];
	d = (tmp / 255.0) * 2 - 1;
	norm.x += d;
	tmp = (unsigned char)pic->cur_obj->surf.mapping.data[pos + 1];
	d = (tmp / 255.0) * 2 - 1;
	norm.y += d;
	tmp = (unsigned char)pic->cur_obj->surf.mapping.data[pos + 2];
	d = (tmp / 255.0) * 2 - 1;
	norm.z += d;
	return (normalize(norm));
}

static t_vec		maping_plane(t_pix *pic, t_point inter, t_vec norm)
{
	double	u;
	double	v;

	if (fabs(norm.x) != 0.0)
	{
		u = fabs(fmod(inter.y * pic->cur_obj->surf.etir.x,
			(float)pic->cur_obj->surf.mapping.width));
		v = fabs(fmod(inter.z * pic->cur_obj->surf.etir.y,
			(float)pic->cur_obj->surf.mapping.height));
	}
	else if (fabs(norm.y) != 0.0)
	{
		u = fabs(fmod(inter.x * pic->cur_obj->surf.etir.x,
			(float)pic->cur_obj->surf.mapping.width));
		v = fabs(fmod(inter.z * pic->cur_obj->surf.etir.y,
			(float)pic->cur_obj->surf.mapping.height));
	}
	else
	{
		u = fabs(fmod(inter.y * pic->cur_obj->surf.etir.x,
			(float)pic->cur_obj->surf.mapping.width));
		v = fabs(fmod(inter.x * pic->cur_obj->surf.etir.y,
			(float)pic->cur_obj->surf.mapping.height));
	}
	return (apply_map(pic, norm, u, v));
}

static t_vec		maping_sphere(t_pix *pic, t_point inter, t_vec norm)
{
	double	u;
	double	v;

	(void)inter;
	u = 0.5 - (atan2((-norm.x), (-norm.y)) / (2.0 * M_PI));
	v = 0.5 + 2.0 * (asin((norm.z)) / (2.0 * M_PI));
	u *= pic->cur_obj->surf.mapping.width;
	v *= pic->cur_obj->surf.mapping.height;
	return (apply_map(pic, norm, u, v));
}

static t_vec		maping_cylcone(t_pix *pic, t_point inter, t_vec norm)
{
	double	u;
	double	v;

	if (pic->cur_obj->type == CYLINDER || pic->cur_obj->type == CONE)
	{
		u = fabs(fmod(inter.y * pic->cur_obj->surf.etir.x,
			(float)pic->cur_obj->surf.mapping.width));
		v = fabs(fmod(inter.z * pic->cur_obj->surf.etir.y,
			(float)pic->cur_obj->surf.mapping.height));
		return (apply_map(pic, norm, u, v));
	}
	return (norm);
}

t_vec				norm_maping(t_pix *pic, t_point inter, t_vec norm)
{
	if (pic->cur_obj->surf.mapping.exist == 1 && pic->cur_obj->type == PLANE)
		return (maping_plane(pic, inter, norm));
	else if (pic->cur_obj->surf.mapping.exist == 1
		&& pic->cur_obj->type == SPHERE)
		return (maping_sphere(pic, inter, norm));
	else if (pic->cur_obj->surf.mapping.exist == 1
		&& (pic->cur_obj->type == CYLINDER || pic->cur_obj->type == CONE))
		return (maping_cylcone(pic, inter, norm));
	return (norm);
}
