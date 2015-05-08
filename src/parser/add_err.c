/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 13:45:19 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/08 13:56:26 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void					add_err(t_pars *e, t_err_type err)
{
	t_err	*node;

	node = ft_memalloc(sizeof(t_err));
	node->err_type = err;
	node->line = e->nb_line;
	if (!e->err_list.size)
		e->err_list.begin = node;
	else
		e->err_list.end->next = node;
	e->err_list.end = node;
	e->err_list.size++;
}
