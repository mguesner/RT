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
	vec_dir->color->b = vec_dir->cur_obj->color.b;
	vec_dir->color->g = vec_dir->cur_obj->color.g;
	vec_dir->color->r = vec_dir->cur_obj->color.r;
}

static void		set_color2(t_pix *vec_dir)
{
	vec_dir->color->b = 0;
	vec_dir->color->g = 0;
	vec_dir->color->r = 0;
}

static void		check(t_pix *vec_dir, int a, int b)
{
	int	l;
	int	a1;
	int	b1;

	l = 200;
	if (a < 0)
		a = abs(a + l);
	if (b < 0)
		b = abs(b + l);
	a1 = (int)(a % (2 * l));
	b1 = (int)(b % (2 * l));
	if ((a1 < l && b1 < l) || (a1 > l && b1 > l))
		set_color1(vec_dir);
	else
		set_color2(vec_dir);
}


void	damier(t_pix *vec_dir)
{
	vec_dir->normale = get_normale(vec_dir, vec_dir->inter);
	if (fabs(vec_dir->normale.x) != 0.0)
		check(vec_dir, (int)vec_dir->inter.y, (int)vec_dir->inter.z);
	else if (fabs(vec_dir->normale.y) != 0.0)
		check(vec_dir, (int)vec_dir->inter.x, (int)vec_dir->inter.z);
	else
		check(vec_dir, (int)vec_dir->inter.y, (int)vec_dir->inter.x);
}

/*

	TRUC CHELOU

	l = 100;
	x1 = (int)(vec_dir->inter.x / l);
	y1 = (int)(vec_dir->inter.y / l);
	z1 = (int)(vec_dir->inter.z / l);
	if (x1 % 2 == 0)
	{
		if (((y1 % 2 == 0) && (z1 % 2 == 0)) ||
		(((y1 % 2 != 0) && (z1 % 2 != 0))))
			set_color1(vec_dir);
		else
			set_color2(vec_dir);
	}
	else
	{
		if ((((y1 % 2 == 0) && (z1 % 2 == 0))) ||
			(((y1 % 2 != 0) && (z1 % 2 != 0))))
			set_color2(vec_dir);
		else
			set_color1(vec_dir);
	}
*/

