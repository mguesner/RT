/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 10:52:23 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/08 14:51:03 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <libft.h>

void	check_line(char *line, t_pars *e)
{
	char	*tmp;

	if ((tmp = ft_strstr(line, "//")))
		*tmp = 0;
	ft_strtrimbadass(line);
	e->tools[e->step](line, e);
}
