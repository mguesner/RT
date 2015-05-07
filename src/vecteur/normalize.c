/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 14:01:46 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/07 14:02:53 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/vecteur.h"

t_vec					normalize(t_vec v)
{
	t_vec	ret;

	ret.x = v.x / norme(v);
	ret.y = v.y / norme(v);
	ret.z = v.z / norme(v);
	return (ret);
}
