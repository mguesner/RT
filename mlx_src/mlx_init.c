/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 14:33:58 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/14 14:26:31 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include "../include/color.h"
#include <stdlib.h>

void		mlx_struct_init(int width, int height, char *win_name, t_libx *m)
{
	if (!(m->mlx = mlx_init()) ||
		!(m->window = mlx_new_window(m->mlx, width, height, win_name)) ||
		!(m->img = mlx_new_image(m->mlx, width, height)) ||
		!(m->data = mlx_get_data_addr(m->img, &(m->bpp), &(m->size_line), &(m->endian))))
		return ;
	m->width = width;
	m->height = height;
}
