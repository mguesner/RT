/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_begin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 12:50:24 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/08 15:25:48 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void					p_begin(char *line, t_pars *e)
{
	if (ft_strncmp(line, "camera", 6))
		e->step = PCAMERA;
	else
		add_err(e, UNKSYMB, line);
	ft_strtrimbadass(line + 6);
	if (ft_strcmp(line + 6, "{"))
		e->scope = OPEN;
	else if (*(line + 6))
		add_err(e, UNKSYMB, line);
}
