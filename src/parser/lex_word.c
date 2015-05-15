/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 10:28:03 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/15 14:10:22 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <errno.h>

void					lex_word(char *line, t_pars *e, int *offset, int size)
{
	int		i;
	char	*value;

	i = 0;
	while (*offset + i < size && (ft_isalnum(*(line + *offset + i))
		|| *(line + *offset + i) == '_'))
		i++;
	if (!(value = ft_memalloc(i + 1)))
		error(errno);
	ft_strncpy(value, line + *offset, i);
	add_lex_node(&e->lex_lst, WORD, value, e->nb_line);
	*offset += i;
}
