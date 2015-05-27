/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_inter_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 14:01:21 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/27 15:02:35 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_inter_word(t_pars *e, t_lex **node)
{
	char		*tmp;

	tmp = (*node)->value;
	if (!strcmp(tmp, "pigment"))
		p_pigment(e, node);
	else if (!strcmp(tmp, "sphere"))
		p_sssphere(e, node);
	else
		add_err(e, UNKOBJ, tmp);
}
