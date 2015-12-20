/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 12:55:34 by bsourd-b          #+#    #+#             */
/*   Updated: 2015/06/03 15:46:33 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static int		up_color_angle(int cur_color, double scalar, double coef)
{
	int new;

	new = cur_color * scalar;
	if (new > cur_color)
		return (cur_color);
	if (new < cur_color * coef)
		return (cur_color * coef);
	return (new);
}

void			set_color_light(t_obj *light, t_pix *pix
	, t_point inter, int nb_spots)
{
	t_vec	dir;
	double	light_dist;
	double	scal;
	double	coef;

	dir = make_vec(light->coord, inter);
	light_dist = norme(dir);
	dir = normalize(dir);
	pix->normale = get_normale(pix, inter);
	vec_reflex(pix);
	scal = fabs(scalar(pix->normale, dir));
	coef = pix->coef;
	coef *= nb_spots;
	if (coef > 0.9)
		coef = 0.9;
	pix->color->b = up_color_angle(pix->color->b, scal, coef);
	pix->color->g = up_color_angle(pix->color->g, scal, coef);
	pix->color->r = up_color_angle(pix->color->r, scal, coef);
}
