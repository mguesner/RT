/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 12:55:34 by bsourd-b          #+#    #+#             */
/*   Updated: 2015/05/19 15:11:34 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <rt.h>
#include <stdio.h>
/*
static int		up_color(int obj_color, int cur_color, double dist, double power)
{
	int	ret;

	ret = (power * obj_color / dist);
	if (cur_color + ret > obj_color)
		return (obj_color);
	if (cur_color + ret > obj_color)
		return (0);
	return (cur_color + ret);
}
*/
static int		up_color_angle(int obj_color, int cur_color, double scalar, double coef)
{
	int new;

	new = obj_color * scalar;
	new = cur_color + new;
	if (new > obj_color)
		return (obj_color);
	if (new < obj_color * coef)
		return (obj_color * coef);
	return (new);
	// (void)cur_color;
	// (void)scalar;
	// return (obj_color);
}

void			set_color_light(t_obj *light, t_pix *pix, t_point inter)
{
	t_vec	dir;
	double	light_dist;
	double	scal;
	double	coef;

	dir = make_vec(light->coord, inter);
	light_dist = norme(dir);
	dir = normalize(dir);
	pix->normale = get_normale(pix, inter);
	scal = fabs(scalar(pix->normale, dir));
	coef = 0.2 - ((pix->cur_obj->color.b + pix->cur_obj->color.g + pix->cur_obj->color.r) / (255 * 3));
	pix->color->b = up_color_angle(pix->cur_obj->color.b, pix->color->b, scal, coef);
	pix->color->g = up_color_angle(pix->cur_obj->color.g, pix->color->g, scal, coef);
	pix->color->r = up_color_angle(pix->cur_obj->color.r, pix->color->r, scal, coef);
}
