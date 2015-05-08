/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 11:10:07 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/08 15:25:02 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void				init_pars(t_pars *e)
{
	e->step = PBEGIN;
	e->nb_line = 1;
	e->err_list.begin = NULL;
	e->err_list.end = NULL;
	e->err_list.size = 0;
	e->scope = CLOSE;
	e->tools[PBEGIN] = &p_begin;
}
