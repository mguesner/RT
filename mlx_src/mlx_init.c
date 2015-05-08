/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 14:33:58 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/08 15:24:36 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include "../include/color.h"


void	set_pixel_to_img(t_libx *m, int pix_x, int pix_y, t_color *color)
{
	int		pos;

	pos = ((pix_y) * (c->img->sili) + pix_x * (m->bpp / 8));
	m->img[pos] = color->b;
	m->img[pos + 1] = color->g;
	m->img[pos + 2] = color->r;
}

t_libx	*mlx_struct_init(int width, int height, char *win_name)
{
	t_libx	*m;

	if (!(m->window = (void *)malloc(sizeof(void *)) ||
		!(m->mlx = (void *)malloc(sizeof(void *))) ||
		!(m->img = (void *)malloc(sizeof(void *)))
		return (NULL);
	if (!(m->mlx = mlx_init() ||
		!(m->window = mlx_new_window(m->mlx, width, height, win_name)) ||
		!(m->img = mlx_new_image(m->mlx, width, height)) ||
		!(m->data = mlx_get_data_addr(m->img, &(m->bpp), &(m->size_line), &(m->endian))))
		return (NULL);
	return (m);
}
