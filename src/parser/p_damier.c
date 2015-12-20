/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_damier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 14:41:19 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/13 16:48:52 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static void				next(t_pars *e, char *value, int *i)
{
	int		dot;
	int		sign;

	dot = 0;
	sign = 0;
	while (ft_isdigit(value[*i]) || value[*i] == '.')
	{
		if (value[*i] == '.')
			dot++;
		(*i)++;
	}
	if (!*i || dot > 1)
		add_err(e, BADARG, value);
	while (value[*i] == ' ' || value[*i] == '\t')
		(*i)++;
	if (value[*i] == ',')
		(*i)++;
	while (value[*i] == ' ' || value[*i] == '\t')
		(*i)++;
}

static void				d_color(t_pars *e, t_lex **node)
{
	t_color	c;
	int		i;
	char	*value;
	t_lex	*tmp;

	tmp = (*node)->next;
	if ((i = 1) && (!tmp || tmp->token_type != VECTOR))
	{
		add_err(e, BADARG, tmp->value);
		return ;
	}
	*node = (*node)->next;
	value = (tmp)->value;
	c.r = atof(value + i) * 255;
	next(e, value, &i);
	c.g = atof(value + i) * 255;
	next(e, value, &i);
	c.b = atof(value + i) * 255;
	next(e, value, &i);
	while (value[i] == ' ' || value[i] == '\t')
		i++;
	if (value[i] != '>')
		add_err(e, BADARG, value);
	if (e->cur)
		e->cur->damier.color = c;
}

static void				d_value(t_pars *e, t_lex **node)
{
	t_lex	*tmp;

	tmp = (*node)->next;
	if (!tmp || tmp->token_type != VALUE)
	{
		add_err(e, BADARG, tmp->value);
		return ;
	}
	*node = (*node)->next;
	e->cur->damier.l = atof(tmp->value);
}

void					p_damier(t_pars *e, t_lex **node)
{
	char	*tmp;
	t_lex	*tmp_node;

	tmp_node = *node;
	tmp = tmp_node->value;
	e->cur->has_damier = 1;
	if (!strcmp(tmp, "long"))
	{
		d_value(e, node);
		return ;
	}
	if (!strcmp(tmp, "color") && tmp_node->next)
	{
		*node = (*node)->next;
		tmp_node = tmp_node->next;
		tmp = tmp_node->value;
	}
	if (!strcmp(tmp, "rgb"))
		d_color(e, node);
	else
		add_err(e, UNKOBJ, tmp);
}