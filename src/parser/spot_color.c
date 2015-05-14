/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 15:14:23 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/13 16:49:25 by mguesner         ###   ########.fr       */
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
	{
		ft_printf("(i = %d, dot = %d)", *i, dot);
		add_err(e, BADARG, value);
	}
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

	ft_printf("color->");
	tmp = (*node)->next;
	if (!tmp || tmp->token_type != VECTOR)
	{
		ft_printf("(fail next)");
		add_err(e, BADARG, tmp->value);
		return ;
	}
	*node = (*node)->next;
	value = (tmp)->value;
	i = 1;
	c.r = atof(value + i) * 255;
	next(e, value, &i);
	c.g = atof(value + i) * 255;
	next(e, value, &i);
	c.b = atof(value + i) * 255;
	next(e, value, &i);
	while (value[i] == ' ' || value[i] == '\t')
		i++;
	if (value[i] != '>')
	{
		ft_printf("(value[i] = %c)", value[i]);
		add_err(e, BADARG, value);
	}
	if (e->cur)
		e->cur->color = c;
}
