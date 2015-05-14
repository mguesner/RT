/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 10:39:28 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/13 15:53:05 by mguesner         ###   ########.fr       */
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
		ft_printf("%s(%d) -> ", tmp->value, e->step);
		e->tools[e->step](e, &tmp);
		ft_putendl("");
		tmp = tmp->next;
	}
}
