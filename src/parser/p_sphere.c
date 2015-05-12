/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_sphere.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 14:18:00 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/12 14:18:57 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_sphere(char *line, t_pars *e, int *off)
{
	int		ret;

	if (!ft_strncmp(line + *off, "}", (ret = 1)))
	{
		e->scope = CLOSE;
		e->err = 0;
		e->step = PBEGIN;
		add_obj_lst(&e->obj_lst, e->cur);
	}
	else if (e->err)
		;
	else if (!ft_strncmp(line + *off, "{", (ret = 1)))
		e->scope = OPEN;
	else if (e->scope == CLOSE)
		add_err(e, SCOPEMISS, line + *off);
	else if (*(line + *off) == '<')
		sphere_loc(line, e, off);
	else
		add_err(e, UNKPARAM, line + *off);
	*off += ret;
}
