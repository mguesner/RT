/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_begin_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 13:32:35 by mguesner          #+#    #+#             */
/*   Updated: 2015/06/01 12:31:14 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static void				p_begin_word3(t_pars *e, t_lex **node)
{
	if (!strcmp((*node)->value, "triangle"))
	{
		e->cur = ft_memalloc(sizeof(t_triangle));
		e->cur->type = TRIANGLE;
		e->step = PTRIANGLE;
	}
	else
		add_err(e, UNKOBJ, (*node)->value);
}

static void				p_begin_word2(t_pars *e, t_lex **node)
{
	if (!strcmp((*node)->value, "plane"))
	{
		e->cur = ft_memalloc(sizeof(t_plane));
		e->cur->type = PLANE;
		e->cur->rot[0][0] = 1;
		e->cur->rot[1][1] = 1;
		e->cur->rot[2][2] = 1;
		e->step = PPLANE;
	}
	else if (!strcmp((*node)->value, "cylinder_42"))
	{
		e->cur = ft_memalloc(sizeof(t_cylinder));
		e->cur->type = CYLINDER;
		e->step = PCYLINDER42;
	}
	else if (!strcmp((*node)->value, "cone_42"))
	{
		e->cur = ft_memalloc(sizeof(t_cone));
		e->cur->type = CONE;
		e->step = PCONE42;
	}
	else
		p_begin_word3(e, node);
}

void					p_begin_word(t_pars *e, t_lex **node)
{
	if (!strcmp((*node)->value, "camera"))
	{
		e->cur = ft_memalloc(sizeof(t_camera));
		e->cur->type = CAM;
		e->step = PCAMERA;
	}
	else if (!strcmp((*node)->value, "light_source"))
	{
		e->cur = ft_memalloc(sizeof(t_light));
		e->cur->type = LIGHT;
		e->step = PSPOT;
	}
	else if (!strcmp((*node)->value, "sphere"))
	{
		e->cur = ft_memalloc(sizeof(t_sphere));
		e->cur->type = SPHERE;
		e->cur->rot[0][0] = 1;
		e->cur->rot[1][1] = 1;
		e->cur->rot[2][2] = 1;
		e->step = PSPHERE;
	}
	else
		p_begin_word2(e, node);
}
