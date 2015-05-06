/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_coef.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:23:23 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/06 16:24:54 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vecteur.h"

t_vec					vec_coef(t_vec a, double r)
{
	t_vec	ret;

	ret.x = r * a.x;
	ret.y = r * a.y;
	ret.z = r * a.z;
	return (ret);
}
