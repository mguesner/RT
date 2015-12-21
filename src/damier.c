/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damier.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsourd-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 11:21:22 by bsourd-b          #+#    #+#             */
/*   Updated: 2015/12/20 11:21:25 by bsourd-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void		put_color(t_pix *vec_dir, t_color color)
{
	vec_dir->color->b = color.b;
	vec_dir->color->g = color.g;
	vec_dir->color->r = color.r;
}

static void		check(t_pix *vec_dir, int a, int b)
{
	int	l;
	int	a1;
	int	b1;

	l = vec_dir->cur_obj->damier.l;
	if (a < 0)
		a = abs(a - l);
	if (b < 0)
		b = abs(b - l);
	a1 = (int)(a % (2 * l));
	b1 = (int)(b % (2 * l));
	if ((a1 < l && b1 < l) || (a1 > l && b1 > l))
		put_color(vec_dir, vec_dir->cur_obj->damier.color);
	else
		put_color(vec_dir, vec_dir->cur_obj->color);
}

void			damier(t_pix *vec_dir)
{
	t_vec		normale;
	double		u;
	double		v;

	if (vec_dir->cur_obj->type == PLANE)
	{
		vec_dir->normale = get_normale(vec_dir, vec_dir->inter);
		if (fabs(vec_dir->normale.x) != 0.0)
			check(vec_dir, (int)vec_dir->inter.y, (int)vec_dir->inter.z);
		else if (fabs(vec_dir->normale.y) != 0.0)
			check(vec_dir, (int)vec_dir->inter.x, (int)vec_dir->inter.z);
		else
			check(vec_dir, (int)vec_dir->inter.y, (int)vec_dir->inter.x);
	}
	else if (vec_dir->cur_obj->type == SPHERE)
	{
		normale = normalize(make_vec(vec_dir->inter, vec_dir->cur_obj->coord));
		u = 0.5 - (atan2((-normale.x), (-normale.y)) / (2.0 * M_PI));
		v = 0.5 + 2.0 * (asin((normale.z)) / (2.0 * M_PI));
		u *= 4000;
		v *= 4000;
		check(vec_dir, u, v);
	}
}
