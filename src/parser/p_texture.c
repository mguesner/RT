/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_texture.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 14:28:42 by mguesner          #+#    #+#             */
/*   Updated: 2015/06/01 13:09:47 by aleung-c         ###   ########.fr       */
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

static t_point			get_point(t_pars *e, char *value)
{
	t_point		ret;
	int			i;

	i = 0;
	if (value[i] != '<')
		add_err(e, BADARG, value);
	i++;
	ret.x = atof(value + i);
	next(e, value, &i);
	ret.y = atof(value + i);
	next(e, value, &i);
	ret.z = atof(value + i);
	next(e, value, &i);
	while (value[i] == ' ' || value[i] == '\t')
		i++;
	if (value[i] != '>')
		add_err(e, BADARG, value);
	return (ret);
}

void					p_texture(t_pars *e, t_lex **node)
{
	char	*tmp;

	tmp = (*node)->value;
	if (!ft_strcmp(tmp, "name") && (*node)->next)
		e->cur->surf.texture = texture_init(e, (*node)->next->value);
	else if (!ft_strcmp(tmp, "norme") && (*node)->next)
		e->cur->surf.mapping = texture_init(e, (*node)->next->value);
	else if (!ft_strcmp(tmp, "offset") && (*node)->next)
		e->cur->surf.offset = get_point(e, (*node)->next->value);
	else if (!ft_strcmp(tmp, "etir") && (*node)->next)
		e->cur->surf.etir = get_point(e, (*node)->next->value);
	else
		add_err(e, UNKOBJ, tmp);
	(*node) = (*node)->next;
}
