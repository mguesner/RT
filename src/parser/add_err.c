/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 13:45:19 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/11 15:07:03 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <errno.h>

static char				*add_err2(char *line)
{
	int		i;

	i = 0;
	while (line[i] && !ft_isblank(line[i]))
		i++;
	line[i] = 0;
	return (ft_strdup(line));
}

void					add_err(t_pars *e, t_err_type err, char *line)
{
	t_err	*node;

	e->err = 1;
	if (!(node = ft_memalloc(sizeof(t_err))))
		error(errno);
	node->err_type = err;
	node->where = add_err2(line);
	node->line = e->nb_line;
	if (!e->err_list.size)
		e->err_list.begin = node;
	else
		e->err_list.end->next = node;
	e->err_list.end = node;
	e->err_list.size++;
}
