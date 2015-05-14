/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_spot_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 14:34:07 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/13 16:35:32 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_spot_word(t_pars *e, t_lex **node)
{
	char	*tmp;
	t_lex	*tmp_node;

	tmp_node = *node;
	tmp = tmp_node->value;
	if (!strcmp(tmp, "color") && tmp_node->next)
	{
		*node = (*node)->next;
		tmp_node = tmp_node->next;
		tmp = tmp_node->value;
	}
	if (!strcmp(tmp, "rgb"))
		color(e, node);
	else
		add_err(e, UNKOBJ, tmp);
}
