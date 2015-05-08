/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 11:10:07 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/08 17:19:28 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static void			init_pars2(t_pars *e)
{
	e->err_msg[UNKOBJ] = "unknow object";
	e->err_msg[UNKPARAM] = "bad parameter";
	e->err_msg[SCOPEMISS] = "'{' missing before";
}

void				init_pars(t_pars *e)
{
	e->step = PBEGIN;
	e->nb_line = 1;
	e->err_list.begin = NULL;
	e->err_list.end = NULL;
	e->err_list.size = 0;
	e->scope = CLOSE;
	e->cur = NULL;
	e->err = 0;
	e->obj_lst.begin = NULL;
	e->obj_lst.end = NULL;
	e->obj_lst.size = 0;
	e->tools[PBEGIN] = &p_begin;
	e->tools[PCAMERA] = &p_camera;
	init_pars2(e);
}
