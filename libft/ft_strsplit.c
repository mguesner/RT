/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:12:08 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/26 13:18:09 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countc(char const *s, char c)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			res++;
		}
		else
			i++;
	}
	if (s[0] == c)
		res--;
	if (s[i - 1] == c)
		res--;
	return (res);
}

static int	ft_untilc(const char *s, char c, int i)
{
	int	res;

	res = 0;
	while (s[res + i] != c && s[res + i])
		res++;
	return (res);
}

static char	**ft_resturn(char **res)
{
	*res = NULL;
	return (res);
}

static char	**ft_strsplit3(char const *s, char c, int *i, char **res)
{
	while (s[i[0]] == c)
		i[0]++;
	if (!*s)
		return (ft_resturn(res));
	res[0] = ft_strnew(1 + ft_untilc(s, c, i[0]));
	while (s[i[0]])
	{
		if (s[i[0]] == c)
		{
			i[1]++;
			i[2] = 0;
			while (s[i[0]] == c)
				i[0]++;
			res[i[1]] = ft_strnew(1 + ft_untilc(s, c, i[0]));
		}
		else
		{
			res[i[1]][i[2]] = s[i[0]];
			i[0]++;
			i[2]++;
		}
	}
	res[i[1] + (i[2] != 0)] = 0;
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i[3];

	if (!s)
		return (0);
	i[1] = 0;
	i[2] = 0;
	i[0] = 0;
	res = (char **)ft_memalloc(((ft_countc(s, c)) + 2) * sizeof(char *));
	res = ft_strsplit3(s, c, i, res);
	return (res);
}
