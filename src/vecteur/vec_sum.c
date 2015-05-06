/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_sum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:22:07 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/06 16:23:10 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vecteur.h"

t_vec					vec_sum(t_vec a, t_vec b)
{
	t_vec	ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;
	return (ret);
}
