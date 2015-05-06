/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_sum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 16:37:57 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/06 16:45:54 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/color.h"

/*
**	TODO : TEST UNITAIRE DE PAPA
*/

t_color					color_sum(t_color a, t_color b)
{
	t_color		ret;

	ret.a = a.a;
	ret.r = a.a * a.r + b.a * b.r;
	ret.g = a.a * a.g + b.a * b.g;
	ret.b = a.a * a.b + b.a * b.b;
	return (ret);
}
