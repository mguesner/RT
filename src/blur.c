/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blur.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 11:56:57 by eruffieu          #+#    #+#             */
/*   Updated: 2015/06/03 15:09:33 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <../include/rt.h>
#include <stdlib.h>

static int		get_five(char *save, t_libx *m, int pos, int t)
{
	int		i;
	int		tot;

	i = save[pos + t];
	if (i < 0)
		i = 255 + i;
	tot = i;
	i = save[(pos + t) + (m->bpp / 8)];
	if (i < 0)
		i = 255 + i;
	tot += i;
	i = save[(pos + t) - (m->bpp / 8)];
	if (i < 0)
		i = 255 + i;
	tot += i;
	i = save[(pos + t) + m->size_line];
	if (i < 0)
		i = 255 + i;
	tot += i;
	i = save[(pos + t) - m->size_line];
	if (i < 0)
		i = 255 + i;
	tot += i;
	return (tot);
}

static void		sweet(int px, int py, t_libx *m, char *save)
{
	int			pos;
	int			pospix;
	int			inc;

	pospix = px + py * 1920;
	pos = ((py) * (m->size_line) + px * (m->bpp / 8));
	inc = m->pix[pospix]->dist - m->ref_dist_mblur;
	while (inc > 0)
	{                                          
		m->data[pos] = get_five(save, m, pos, 0) / 5.0;
		m->data[pos + 1] = get_five(save, m, pos, 1) / 5.0;
		m->data[pos + 2] = get_five(save, m, pos, 2) / 5.0;
		inc--;
	}
}

static char		*copy_to(t_libx *m)
{
	char	*save;
	int		i;
	int		px;

	i = (1080 * (m->size_line) + 1920 * (m->bpp / 8));
	if (!(save = (char *)malloc(sizeof(char) * i + 1)))
		exit (0);
	px = 0;
	m->ref_dist_mblur = 100000000000;
	while (px < 1080 * 1920)
	{
		if (m->pix[px]->dist)
		{
			if (m->pix[px]->dist < m->ref_dist_mblur)
				m->ref_dist_mblur = m->pix[px]->dist;
		}
		px += 1;
	}
	return (save);
}

void			blur(t_libx *m)
{
	int		px;
	int		py;
	char	*save;

	save = copy_to(m);
	save = ft_memcpy(save, m->data, (1080 * (m->size_line) +
		1920 * (m->bpp / 8)));
	py = 3;
	while (py < 1079)
	{
		px = 0;
		while (px < 1919)
		{
			sweet(px, py, m, save);
			px++;
		}
		py++;
	}
}