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
#include <stdio.h>

static t_vec		apply_map(t_pix *pic, t_vec norm, double u, double v)
{
	int				pos;
	double 			d;
	unsigned char	tmp;

	pos = ((int)u * (pic->cur_obj->texture.bpp / 8)
		+ (int)v * pic->cur_obj->texture.size_line);
	tmp = (unsigned char)pic->cur_obj->texture.data[pos];
	d = (tmp / 255.0) * 2 + 1;
	norm.x += d;
	tmp = (unsigned char)pic->cur_obj->texture.data[pos + 1];
	d = (tmp / 255.0) * 2 + 1;
	norm.y += d;
	tmp = (unsigned char)pic->cur_obj->texture.data[pos + 2];
	d = (tmp / 255.0) * 2 + 1;
	norm.z += d;
	return (normalize(norm));
}

static t_vec		maping_plane(t_pix *pic, t_point inter, t_vec norm)
{	
	double	u;
	double	v;

	if (fabs(norm.x) != 0.0)
	{
		u = fabs(fmod(inter.y,
			(float)pic->cur_obj->texture.width));
		v = fabs(fmod(inter.z,
			(float)pic->cur_obj->texture.height));
	}
	else if (fabs(norm.y) != 0.0)
	{
		u = fabs(fmod(inter.x,
			(float)pic->cur_obj->texture.width));
		v = fabs(fmod(inter.z,
			(float)pic->cur_obj->texture.height));
	}
	else
	{
		u = fabs(fmod(inter.y,
			(float)pic->cur_obj->texture.width));
		v = fabs(fmod(inter.x,
			(float)pic->cur_obj->texture.height));
	}
	return (apply_map(pic, norm, u, v));
}

t_vec	norm_maping(t_pix *pic, t_point inter, t_vec norm)
{
	if (pic->cur_obj->texture.exist == 1 && pic->cur_obj->type == PLANE)
		return(maping_plane(pic, inter, norm));
	return (norm);
}