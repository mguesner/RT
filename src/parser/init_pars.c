/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 11:10:07 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/15 14:26:16 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static void			init_pars2(t_pars *e)
{
	e->err_msg[UNKSYMB] = "unknow symbol";
	e->err_msg[UNKOBJ] = "unknow object";
	e->err_msg[UNKPARAM] = "bad parameter";
	e->err_msg[SCOPEMISS] = "unexpected scope";
	e->err_msg[BADARG] = "bad argument";
}

void				init_pars(t_pars *e)
{
	ft_bzero(e, sizeof(t_pars));
	e->step = PBEGIN;
	e->substep = SSBEGIN;
	e->scope = 0;
	e->nb_line = 1;
	e->err_list.begin = NULL;
	e->err_list.end = NULL;
	e->err_list.size = 0;
	e->cur = NULL;
	e->err = 0;
	e->obj_lst.begin = NULL;
	e->obj_lst.end = NULL;
	e->obj_lst.size = 0;
	e->tools[PBEGIN] = &p_begin;
	e->tools[PCAMERA] = &p_camera;
	e->tools[PSPOT] = &p_spot;
	e->tools[PPLANE] = &p_plane;
	e->tools[PSPHERE] = &p_sphere;
	e->tools[PCYLINDER42] = &p_cylinder42;
	e->tools[PCONE42] = &p_cone42;
	init_pars2(e);
}
