/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_begin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 12:50:24 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/08 12:57:17 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void					p_begin(char *line, t_pars *e)
{
	if (ft_strncmp(line, "camera", 6))
		e->step = PCAMERA;
	else
		add_err(e, UNKSYMB);
}
