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

static int get_five(char *save, t_libx *m, int pos, int t)
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

static void	get_middle_color(char *save, int px, int py, t_libx *m)
{
	int		pos;
	double		one;
	double		two;
	double		three;

	pos = ((py) * (m->size_line) + px * (m->bpp / 8));
	one = get_five(save, m, pos, 0) / 5.0;
	two = get_five(save, m, pos, 1) / 5.0;
	three = get_five(save, m, pos, 2) / 5.0;
	m->data[pos] = one;
	m->data[pos + 1] = two;
	m->data[pos + 2] = three;
}

static char	*copy_to(t_libx *m)
{
	char	*save;
	int		i;

	i = (1080 * (m->size_line) + 1920 * (m->bpp / 8));
	if (!(save = (char *)malloc(sizeof(char) * i + 1)))
		exit (0);
	return (save);
}

void		antialiasing(t_libx *m)
{
	char	*save;
	int		px;
	int		py;

	save = copy_to(m);
	save = ft_memcpy(save, m->data, (1080 * (m->size_line) +
		1920 * (m->bpp / 8)));
	py = 2;
	while (py < 1077)
	{
		px = 0;
		while (px < 1919)
		{
			get_middle_color(save, px, py, m);
			px++;
		}
		py++;
	}
}
