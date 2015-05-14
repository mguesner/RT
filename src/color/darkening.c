/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darkening.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 13:52:04 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/14 11:25:57 by bsourd-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/color.h"

t_color					darkening(t_color c)
{
	t_color		ret;

	ret.r = c.r - 10;
	if (ret.r < 0)
		ret.r = 0;
	ret.g = c.g - 10;
	if (ret.g < 0)
		ret.g = 0;
	ret.b = c.b - 10;
	if (ret.b < 0)
		ret.b = 0;
	return (ret);
}
