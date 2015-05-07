/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_diff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 13:49:03 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/07 13:49:41 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/color.h"

t_color					color_diff(t_color a, t_color b)
{
	t_color		ret;

	ret.a = a.a;
	ret.r = a.a * a.r - b.a * b.r;
	ret.g = a.a * a.g - b.a * b.g;
	ret.b = a.a * a.b - b.a * b.b;
	return (ret);
}
