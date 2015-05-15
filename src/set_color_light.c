/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguezell <nguezell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 12:55:34 by bsourd-b          #+#    #+#             */
/*   Updated: 2015/05/15 16:30:28 by nguezell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static t_vec	get_norm(t_obj *obj, t_point inter)
{
	if (obj->type == PLANE)
		return (((t_plane *)obj)->norm);
	if (obj->type == CONE)
		return (((t_cone *)obj)->dir);
	if (obj->type == CYLINDER)
		return (((t_cylinder *)obj)->dir);
	else // if (obj->type == SPHERE)
		return (normalize(make_vec(obj->coord, inter)));
}
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
	return (obj_color);
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

	t_vec	normale;
	double	scal;

	normale = get_norm(pix->cur_obj, inter);
	scal = fabs(scalar(normale, dir));

	pix->color->b = up_color_angle(pix->cur_obj->color.b, pix->color->b, scal);
	pix->color->g = up_color_angle(pix->cur_obj->color.g, pix->color->g, scal);
	pix->color->r = up_color_angle(pix->cur_obj->color.r, pix->color->r, scal);

}
