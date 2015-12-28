/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsourd-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 12:06:18 by bsourd-b          #+#    #+#             */
/*   Updated: 2015/12/27 12:06:22 by bsourd-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void		put_color(t_pix *vec_dir, float val)
{
	unsigned char	c;

	c = (unsigned char)vec_dir->cur_obj->color.b;
	c *= val;
	vec_dir->color->b = (char)c;
	c = (unsigned char)vec_dir->cur_obj->color.g;
	c *= val;
	vec_dir->color->g = (char)c;
	c = (unsigned char)vec_dir->cur_obj->color.r;
	c *= val;
	vec_dir->color->r = (char)c;
	vec_dir->color->b = vec_dir->color->b < 0 ?
			255 + vec_dir->color->b : vec_dir->color->b;
	vec_dir->color->r = vec_dir->color->r < 0 ?
			255 + vec_dir->color->r : vec_dir->color->r;
	vec_dir->color->g = vec_dir->color->g < 0 ?
			255 + vec_dir->color->g : vec_dir->color->g;
}

void			perlin(t_pix *vec_dir)
{
	double		val;
	double		res;

	res = vec_dir->cur_obj->perlin;
	if (vec_dir->cur_obj->type == PLANE)
	{
		vec_dir->normale = get_normale(vec_dir, vec_dir->inter);
		if (fabs(vec_dir->normale.x) != 0.0)
			val = getperl((int)fabs(vec_dir->inter.y),
			(int)fabs(vec_dir->inter.z), res);
		else if (fabs(vec_dir->normale.y) != 0.0)
			val = getperl((int)fabs(vec_dir->inter.x),
				(int)fabs(vec_dir->inter.z), res);
		else
			val = getperl((int)fabs(vec_dir->inter.y),
				(int)fabs(vec_dir->inter.x), res);
		put_color(vec_dir, (val + 1) / 2);
	}
	else if (vec_dir->cur_obj->type == CYLINDER
		|| vec_dir->cur_obj->type == CONE)
	{
		val = getperl((int)fabs(vec_dir->inter.x),
			(int)fabs(vec_dir->inter.y), res);
		put_color(vec_dir, (val + 1) / 2);
	}
}
