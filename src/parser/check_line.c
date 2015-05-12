/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 10:52:23 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/12 15:20:25 by mguesner         ###   ########.fr       */
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
	ft_strtrimbadass(line + off);
	while (*(line + off))
	{
		// ft_printf("%d__%s__ -> %d\n", e->nb_line, line + off, e->step);
		e->tools[e->step](line, e, &off);
		if (e->err)
			break ;
		ft_strtrimbadass(line + off);
	}
}
