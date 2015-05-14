/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 14:01:46 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/13 16:17:47 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vecteur.h"

t_vec					normalize(t_vec v)
{
	t_vec	ret;
	double normel;

	normel = norme(v);
	ret.x = v.x / normel;
	ret.y = v.y / normel;
	ret.z = v.z / normel;
	return (ret);
}
