/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 12:34:32 by mguesner          #+#    #+#             */
/*   Updated: 2015/06/02 13:55:17 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <errno.h>

void					lex_value(char *line, t_pars *e, int *offset, int size)
{
	int		i;
	char	*value;

	i = 0;
	if (*(line + *offset) == '-')
		i++;
	while (*offset + i < size && (ft_isdigit(*(line + *offset + i))
		|| *(line + *offset + i) == '.'))
		i++;
	if (!(value = ft_memalloc(i + 1)))
		error(errno);
	ft_strncpy(value, line + *offset, i);
	add_lex_node(&e->lex_lst, VALUE, value, e->nb_line);
	*offset += i;
}
