/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brightening.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 13:54:29 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/07 13:56:15 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/color.h"

t_color					brighteing(t_color c)
{
	t_color		ret;

	ret.r = c.r + 10;
	ret.g = c.g + 10;
	ret.b = c.b + 10;
	return (ret);
}
