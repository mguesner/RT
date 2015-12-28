/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_plane_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 14:25:29 by mguesner          #+#    #+#             */
/*   Updated: 2015/06/02 14:09:48 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static void				p_perlin(t_pars *e, t_lex **node)
{
	(*node) = (*node)->next;
	if (!*node)
		add_err(e, BADARG, "");
	else if ((*node)->token_type != VALUE)
		add_err(e, BADARG, (*node)->value);
	else
		e->cur->perlin = atof((*node)->value);
}

void					p_plane_word(t_pars *e, t_lex **node)
{
	char		*tmp;
	t_f_parse	tools[NBSUBSTEP];

	tools[SSPIGMENT] = &p_pigment;
	tools[SSTEXTURE] = &p_texture;
	tools[SSFINISH] = &p_finish;
	tools[SSDAMIER] = &p_damier;
	if (e->substep != SSBEGIN)
	{
		tools[e->substep](e, node);
		return ;
	}
	tmp = (*node)->value;
	if (!strcmp(tmp, "pigment"))
		e->substep = SSPIGMENT;
	else if (!strcmp(tmp, "texture"))
		e->substep = SSTEXTURE;
	else if (!strcmp(tmp, "finish"))
		e->substep = SSFINISH;
	else if (!strcmp(tmp, "damier"))
		e->substep = SSDAMIER;
	else if (!strcmp(tmp, "end"))
		p_limit(e, node);
	else if (!strcmp(tmp, "perlin"))
		p_perlin(e, node);
	else
		add_err(e, UNKOBJ, tmp);
}
