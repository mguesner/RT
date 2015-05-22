/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 15:31:26 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/22 14:36:04 by eruffieu         ###   ########.fr       */
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

t_color					color_sum(t_color a, t_color b);
t_color					color_diff(t_color a, t_color b);
t_color					darkening(t_color c);
t_color					brighteing(t_color c);

#endif
