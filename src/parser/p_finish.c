/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_finish.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 11:24:50 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/26 12:33:05 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_finish(t_pars *e, t_lex **node)
{
	char	*tmp;

	tmp = (*node)->value;
	if (!ft_strcmp(tmp, "specular"))
		p_specular(e, node);
	else if (!ft_strcmp(tmp, "reflection"))
		p_reflection(e, node);
	else
		add_err(e, UNKOBJ, tmp);
}
