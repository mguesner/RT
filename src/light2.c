/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsourd-b <bsourd-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 13:32:19 by bsourd-b          #+#    #+#             */
/*   Updated: 2015/06/02 13:32:20 by bsourd-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <matrice.h>

void	shadow_subfunc(t_pix **vec_dir, double d[3], t_obj_list *tmp)
{
	(*vec_dir)->in_shadow = tmp->obj;
	(*vec_dir)->shadow_dist = d[2];
	(*vec_dir)->light_dist = d[1];
	(*vec_dir)->shadow_obj = tmp->obj;
	d[0] = d[2];
}
