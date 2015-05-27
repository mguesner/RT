/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 10:39:28 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/27 15:04:08 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/stat.h>

void	parser(t_pars *e)
{
	t_lex		*tmp;

	tmp = e->lex_lst.begin;
	while (tmp)
	{
		e->tools[e->step](e, &tmp);
		e->nb_line = tmp->line;
		tmp = tmp->next;
	}
}
