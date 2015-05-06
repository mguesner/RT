/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 15:31:26 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/06 15:51:06 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct			s_color
{
	int					a;
	int					r;
	int					g;
	int					b;
}						t_color;

t_color					color_sum(t_color, t_color);
t_color					darkening(t_color);
t_color					brighteing(t_color);

#endif
