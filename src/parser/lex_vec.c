/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 12:15:25 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/15 14:10:38 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <errno.h>

void					lex_vec(char *line, t_pars *e, int *offset, int size)
{
	int		i;
	char	*value;

	i = 0;
	while (*offset + i < size && *(line + *offset + i) != '>')
		i++;
	i++;
	if (!(value = ft_memalloc(i + 1)))
		error(errno);
	ft_strncpy(value, line + *offset, i);
	add_lex_node(&e->lex_lst, VECTOR, value, e->nb_line);
	*offset += i;
}
