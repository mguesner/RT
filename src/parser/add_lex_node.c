/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_lex_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 10:42:08 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/15 14:09:13 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <errno.h>

void					add_lex_node(t_lex_begin *begin, t_token token
	, char *value, int line)
{
	t_lex	*node;

	if (!(node = ft_memalloc(sizeof(t_lex))))
		error(errno);
	node->token_type = token;
	node->value = value;
	node->line = line;
	if (!begin->size)
		begin->begin = node;
	else
		begin->end->next = node;
	begin->size++;
	begin->end = node;
}
