/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 12:55:34 by bsourd-b          #+#    #+#             */
/*   Updated: 2015/05/14 15:28:24 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static int	up_color(int obj_color, int cur_color, double dist, double power)
{
	int	ret;

	ret = (power * obj_color / dist);
	if (cur_color + ret > obj_color)
		return (obj_color);
	if (cur_color + ret > obj_color)
		return (0);
	return (cur_color + ret);
}

void		set_color_light(t_obj *light, t_pix *pix, t_point inter)
{
	t_vec	dir;
	double	light_dist;

	dir = make_vec(light->coord, inter);
	light_dist = norme(dir);
	dir = normalize(dir);
	pix->color->b = up_color(pix->cur_obj->color.b, pix->color->b, light_dist, 1000);
	pix->color->g = up_color(pix->cur_obj->color.g, pix->color->g, light_dist, 1000);
	pix->color->r = up_color(pix->cur_obj->color.r, pix->color->r, light_dist, 1800);
}
