/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 15:14:23 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/14 14:55:05 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdlib.h>

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

void					color(t_pars *e, t_lex **node)
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
		e->cur->color = c;
}
