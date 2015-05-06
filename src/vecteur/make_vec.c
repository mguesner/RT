/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_vec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:27:22 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/06 16:28:13 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vecteur.h"

t_vec					make_vec(t_point a, t_point b)
{
	t_vec	ret;

	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;
	return (ret);
}
