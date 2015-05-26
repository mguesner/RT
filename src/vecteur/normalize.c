/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 14:01:46 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/26 13:14:19 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vecteur.h"

t_vec					normalize(t_vec v)
{
	t_vec	ret;
	double	normal;

	normal = norme(v);
	ret.x = v.x / normal;
	ret.y = v.y / normal;
	ret.z = v.z / normal;
	return (ret);
}
