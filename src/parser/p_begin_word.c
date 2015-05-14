/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_begin_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 13:32:35 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/14 13:03:12 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_begin_word(t_pars *e, t_lex **node)
{
	char	*tmp;

	tmp = (*node)->value;
	ft_putstr("p_begin_word->");
	ft_putstr(tmp);
	if (!strcmp(tmp, "camera"))
	{
		e->cur = ft_memalloc(sizeof(t_camera));
		e->cur->type = CAM;
		e->step = PCAMERA;
		ft_printf(", step to %d", e->step);
	}
	else if (!strcmp(tmp, "light_source"))
	{
		e->cur = ft_memalloc(sizeof(t_light));
		e->cur->type = LIGHT;
		e->step = PSPOT;
		ft_printf(", step to %d", e->step);
	}
	else if (!strcmp(tmp, "sphere"))
	{
		e->cur = ft_memalloc(sizeof(t_sphere));
		e->cur->type = SPHERE;
		e->step = PSPHERE;
		ft_printf(", step to %d", e->step);
	}
	else if (!strcmp(tmp, "plane"))
	{
		e->cur = ft_memalloc(sizeof(t_plane));
		e->cur->type = PLANE;
		e->step = PPLANE;
		ft_printf(", step to %d", e->step);
	}
	else if (!strcmp(tmp, "cylinder_42"))
	{
		e->cur = ft_memalloc(sizeof(t_cylinder));
		e->cur->type = CYLINDER;
		e->step = PCYLINDER42;
		ft_printf(", step to %d", e->step);
	}
	else if (!strcmp(tmp, "cone_42"))
	{
		e->cur = ft_memalloc(sizeof(t_cone));
		e->cur->type = CONE;
		e->step = PCONE42;
		ft_printf(", step to %d", e->step);
	}
	else
		add_err(e, UNKOBJ, tmp);
}
