/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_begin_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 13:32:35 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/14 14:53:11 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static void				p_begin_word2(t_pars *e, t_lex **node)
{
	char	*tmp;

	tmp = (*node)->value;
	if (!strcmp(tmp, "plane"))
	{
		e->cur = ft_memalloc(sizeof(t_plane));
		e->cur->type = PLANE;
		e->step = PPLANE;
	}
	else if (!strcmp(tmp, "cylinder_42"))
	{
		e->cur = ft_memalloc(sizeof(t_cylinder));
		e->cur->type = CYLINDER;
		e->step = PCYLINDER42;
	}
	else if (!strcmp(tmp, "cone_42"))
	{
		e->cur = ft_memalloc(sizeof(t_cone));
		e->cur->type = CONE;
		e->step = PCONE42;
	}
	else
		add_err(e, UNKOBJ, tmp);
}

void					p_begin_word(t_pars *e, t_lex **node)
{
	char	*tmp;

	tmp = (*node)->value;
	if (!strcmp(tmp, "camera"))
	{
		e->cur = ft_memalloc(sizeof(t_camera));
		e->cur->type = CAM;
		e->step = PCAMERA;
	}
	else if (!strcmp(tmp, "light_source"))
	{
		e->cur = ft_memalloc(sizeof(t_light));
		e->cur->type = LIGHT;
		e->step = PSPOT;
	}
	else if (!strcmp(tmp, "sphere"))
	{
		e->cur = ft_memalloc(sizeof(t_sphere));
		e->cur->type = SPHERE;
		e->step = PSPHERE;
	}
	else
		p_begin_word2(e, node);
}
