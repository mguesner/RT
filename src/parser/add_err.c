/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 13:45:19 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/08 15:18:44 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <errno.h>

void					add_err(t_pars *e, t_err_type err, char *line)
{
	t_err	*node;

	if (!(node = ft_memalloc(sizeof(t_err))))
		error(errno);
	node->err_type = err;
	node->where = ft_strdup(line);
	node->line = e->nb_line;
	if (!e->err_list.size)
		e->err_list.begin = node;
	else
		e->err_list.end->next = node;
	e->err_list.end = node;
	e->err_list.size++;
}
