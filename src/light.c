/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 10:03:28 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/13 13:08:24 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <vecteur.h>
#include <stdio.h>

static t_point	intersection_point(double r, t_vec x)
{
	t_point		ret;

	ret.x = r * a.x;
	ret.y = r * a.y;
	ret.z = r * a.z;
	return (ret);
}

static int		shadow()
{

}

void			calc_lum(t_libx *mlx, double dist, t_vec vec_dir)
{
	t_point		inter_point;
	t_obj_list	*tmp;
	t_obj_list	*tmp2;

	inter_point = intersection_point(dist, vec_dir);

}
