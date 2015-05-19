/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 12:55:34 by bsourd-b          #+#    #+#             */
/*   Updated: 2015/05/19 15:53:36 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <rt.h>
#include <stdio.h>

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
	if (pix->cur_obj->type == SPHERE && pix->cur_obj->texture.exist == 1)
		texture_func(pix);
	coef = 0.2 - ((pix->cur_obj->color.b + pix->cur_obj->color.g + pix->cur_obj->color.r) / (255 * 3));
	pix->color->b = up_color_angle(pix->cur_obj->color.b, pix->color->b, scal, coef);
	pix->color->g = up_color_angle(pix->cur_obj->color.g, pix->color->g, scal, coef);
	pix->color->r = up_color_angle(pix->cur_obj->color.r, pix->color->r, scal, coef);
}
