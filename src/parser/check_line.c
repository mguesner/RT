/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 10:52:23 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/11 14:13:01 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <libft.h>

void	check_line(char *line, t_pars *e)
{
	char	*tmp;
	int		off;

	off = 0;
	if ((tmp = ft_strstr(line, "//")))
		*tmp = 0;
	while (*(line + off))
	{
		// ft_printf("__%s__ -> %d\n", line + off, *(line + off));
		ft_strtrimbadass(line + off);
		e->tools[e->step](line, e, &off);
		if (e->err)
			break ;
	}
}
