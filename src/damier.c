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

static void		set_color1(t_pix *vec_dir)
{
	vec_dir->color->b = 200;
	vec_dir->color->g = 200;
	vec_dir->color->r = 200;
}

static void		set_color2(t_pix *vec_dir)
{
	vec_dir->color->b = 50;
	vec_dir->color->g = 50;
	vec_dir->color->r = 50;
}

static void		check(t_pix *vec_dir, int a, int b)
{
	int	l;
	int	a1;
	int	b1;

	l = 200;
	if (a < 0)
		a = abs(a - l);
	if (b < 0)
		b = abs(b - l);
	a1 = (int)(a % (2 * l));
	b1 = (int)(b % (2 * l));
	if ((a1 < l && b1 < l) || (a1 > l && b1 > l))
		set_color2(vec_dir);
	else
		set_color1(vec_dir);
}

void	damier(t_pix *vec_dir)
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
