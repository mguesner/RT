/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 10:50:50 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/26 13:30:47 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word2(char *str, char c, int *ret, int i)
{
	if (str[1] == c && str[0] != '\\')
		(*ret)--;
	if (str[i - 1] == c && (i - 2) >= 0 && str[i - 2] != '\\')
		(*ret)--;
	return (*ret);
}

static int	ft_count_word(char *str, char c)
{
	int		ret;
	int		i;
	int		slash;

	ret = 1;
	i = 1;
	slash = 0;
	while (str[i])
	{
		if (!slash && str[i - 1] != '\\' && str[i] == c)
		{
			while (str[i] == c)
				i++;
			ret++;
		}
		else
		{
			if (str[i] == '\\' && str[i - 1] == '\\' && !slash)
				slash = 1;
			else
				slash = 0;
			i++;
		}
	}
	return (ft_count_word2(str, c, &ret, i));
}

static int	ft_untilc(char *str, char c)
{
	int		ret;
	int		slash;

	ret = 1;
	slash = 0;
	while (str[ret] && ((str[ret - 1] == '\\' && !slash) || str[ret] != c))
	{
		if (str[ret - 1] == '\\' && !slash)
			slash = 1;
		else
			slash = 0;
		ret++;
	}
	return (ret);
}

char		**ft_strsplit2(char *str, char c)
{
	int		word;
	char	**tab;
	int		i;
	int		j;
	int		tmp;

	word = ft_count_word(str, c);
	tab = (char **)ft_memalloc((word + 1) * sizeof(char *));
	j = 0;
	i = 0;
	while (i < word)
	{
		tmp = ft_untilc(&(str[j]), c);
		tab[i] = ft_strsub(str, j, tmp);
		i++;
		j = j + tmp + 1;
	}
	return (tab);
}
