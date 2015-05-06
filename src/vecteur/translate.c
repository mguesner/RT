/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:25:11 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/06 16:33:03 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vecteur.h"

t_point					translate(t_point p, t_vec v)
{
	t_point		ret;

	ret.x = p.x + v.x;
	ret.y = p.y + v.y;
	ret.z = p.z + v.z;
	return (ret);
}
