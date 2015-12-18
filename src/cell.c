/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiasing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 11:56:57 by eruffieu          #+#    #+#             */
/*   Updated: 2015/06/03 15:09:33 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/rt.h>
#include <stdlib.h>

static int		diff_obj(t_obj *one, t_obj *two)
{
	if (one->type != two->type)
		return (1);
	else if (one->color.r != two->color.r || one->color.b != two->color.b
		|| one->color.g != two->color.g)
		return (1);
	else if (one->coord.x != two->coord.x || one->coord.y != two->coord.y
		|| one->coord.z != two->coord.z)
		return (1);
	return (0);
}

static int		compare_obj(t_libx *m, int pospix)
{
	if (diff_obj(m->pix[pospix]->cur_obj,
		m->pix[pospix - 1]->cur_obj))
		return (1);
	else if (diff_obj(m->pix[pospix]->cur_obj,
		m->pix[pospix + 1]->cur_obj))
		return (1);
	else if (diff_obj(m->pix[pospix]->cur_obj,
		m->pix[pospix + 1920]->cur_obj))
		return (1);
	else if (diff_obj(m->pix[pospix]->cur_obj,
		m->pix[pospix - 1920]->cur_obj))
		return (1);
	return (0);
}

static void		sweet(int px, int py, t_libx *m)
{
	int			pos;
	int			pospix;

	pospix = px + py * 1920;
	pos = ((py) * (m->size_line) + px * (m->bpp / 8));
	if (m->pix[pospix]->cur_obj && m->pix[pospix + 1]->cur_obj)
	{                                          
		if (compare_obj(m, pospix))
		{
			m->data[pos] = 0;
			m->data[pos + 1] = 0;
			m->data[pos + 2] = 0;
		}
	}
	else
	{
		m->data[pos] = 0;
		m->data[pos + 1] = 0;
		m->data[pos + 2] = 0;
	}
}

void			cshade(t_libx *m)
{
	int		px;
	int		py;

	py = 3;
	while (py < 1077)
	{
		px = 0;
		while (px < 1919)
		{
			sweet(px, py, m);
			px++;
		}
		py++;
	}

}