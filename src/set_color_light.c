/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 12:55:34 by bsourd-b          #+#    #+#             */
/*   Updated: 2015/05/18 16:28:46 by eruffieu         ###   ########.fr       */
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
static int		up_color_angle(int obj_color, int cur_color, double scalar)
{
	int new;

	new = obj_color * scalar;
	new = cur_color + new;
	if (new > obj_color)
		return (obj_color);
	if (new < 0)
		return (0);
	return (new);
	// (void)cur_color;
	// (void)scalar;
	// return (obj_color);
}

void			set_color_light(t_obj *light, t_pix *pix, t_point inter)
{
	t_vec	dir;
	double	light_dist;

	dir = make_vec(light->coord, inter);
	light_dist = norme(dir);
	dir = normalize(dir);
//	pix->color->b = up_color(pix->cur_obj->color.b, pix->color->b, light_dist, 1000);
//	pix->color->g = up_color(pix->cur_obj->color.g, pix->color->g, light_dist, 1000);
//	pix->color->r = up_color(pix->cur_obj->color.r, pix->color->r, light_dist, 1000);
	// t_vec	normale;
	double	scal;

	pix->normale = get_normale(pix, inter);
	// scal = scalar(pix->normale, dir);
	// if (scal < 0.0)
	// 	scal = -scal;
	scal = fabs(scalar(pix->normale, dir));
	// printf("%f\n", scal);

	pix->color->b = up_color_angle(pix->cur_obj->color.b, pix->color->b, scal);
	pix->color->g = up_color_angle(pix->cur_obj->color.g, pix->color->g, scal);
	pix->color->r = up_color_angle(pix->cur_obj->color.r, pix->color->r, scal);
}
