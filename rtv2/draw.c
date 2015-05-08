/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 13:47:01 by eruffieu          #+#    #+#             */
/*   Updated: 2015/02/27 14:14:49 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		draw(t_all *c)
{
	double	dist_spot;
	int		blue;
	int		red;
	int		green;

	dist_spot = calc_dist_spot(c);
	if (dist_spot >= c->list_spot->obj->other)
		dist_spot = c->list_spot->obj->other;
	else if (dist_spot <= 0.0)
		dist_spot = 0.0;
	if ((blue = c->first_obj->obj->blue_color - (dist_spot * 255.0 / c->list_spot->obj->other)) < 0)
		blue = 0;
	if ((green = c->first_obj->obj->green_color - (dist_spot * 255.0 / c->list_spot->obj->other)) < 0)
		green = 0;
	if ((red = c->first_obj->obj->red_color - (dist_spot * 255.0 / c->list_spot->obj->other)) < 0)
		red = 0;
	c->libx->data[(c->y_pix * c->libx->sizeline) + c->x_pix * (c->libx->bpp / 8)] = blue;
	c->libx->data[(c->y_pix * c->libx->sizeline) + c->x_pix * (c->libx->bpp / 8) + 1] = green;
	c->libx->data[(c->y_pix * c->libx->sizeline) + c->x_pix * (c->libx->bpp / 8) + 2] = red;
}
