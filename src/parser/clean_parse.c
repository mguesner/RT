/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 14:08:17 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/14 14:16:15 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static void				clean_err(t_err_begin err)
{
	t_err				*tmp;
	t_err				*next;

	tmp = err.begin;
	next = tmp;
	while (tmp)
	{
		next = next->next;
		ft_memdel((void **)&tmp->where);
		ft_memdel((void **)&tmp);
		tmp = next;
	}
}

static void				clean_lex(t_lex_begin err)
{
	t_lex				*tmp;
	t_lex				*next;

	tmp = err.begin;
	next = tmp;
	while (tmp)
	{
		next = next->next;
		ft_memdel((void **)&tmp->value);
		ft_memdel((void **)&tmp);
		tmp = next;
	}
}

void					clean_pars(t_pars *e)
{

	if (e->err_list.size)
		clean_err(e->err_list);
	if (e->lex_lst.size)
		clean_lex(e->lex_lst);
}
