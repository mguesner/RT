/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sepia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsourd-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 14:35:11 by bsourd-b          #+#    #+#             */
/*   Updated: 2015/12/19 14:35:13 by bsourd-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void		filter_pix(int px, int py, t_libx *m)
{
	int				pos;
	unsigned char	in[3];
	int				out[3];

	pos = ((py) * (m->size_line) + px * (m->bpp / 8));
	in[0] = (unsigned char)m->data[pos];
	in[1] = (unsigned char)m->data[pos + 1];
	in[2] = (unsigned char)m->data[pos + 2];
	out[2] = (in[0] * 0.393) + (in[1] * 0.769) + (in[2] * 0.189);
	out[1] = (in[0] * 0.349) + (in[1] * 0.686) + (in[2] * 0.168);
	out[0] = (in[0] * 0.272) + (in[1] * 0.534) + (in[2] * 0.131);
	if (out[0] > 255)
		out[0] = 255;
	if (out[1] > 255)
		out[1] = 255;
	if (out[2] > 255)
		out[2] = 255;
	m->data[pos] = (char)out[0];
	m->data[pos + 1] = (char)out[1];
	m->data[pos + 2] = (char)out[2];
}		

void			sepia(t_libx *m)
{
	int		px;
	int		py;

	py = 0;
	while (py < 1080)
	{
		px = 0;
		while (px < 1920)
		{
			filter_pix(px, py, m);
			px++;
		}
		py++;
	}

}
