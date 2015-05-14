/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_openscope.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 13:39:33 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/13 16:39:42 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_openscope(t_pars *e, t_lex **node)
{
	ft_putstr("open scope");
	e->scope++;
	(void)node;
}
