/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:57:22 by mguesner          #+#    #+#             */
/*   Updated: 2014/02/02 08:43:39 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_clean(const char *str)
{
	int		i;

	i = 0;
	while (ft_isblank(str[i]))
		i++;
	return (i);
}

static size_t	ft_strlendigit(const char *str, int i)
{
	int		res;

	res = 0;
	while (ft_isdigit(str[res + i]))
		res++;
	return (res + i);
}

int				ft_atoi(const char *str)
{
	int		i;
	int		signe;
	int		res;
	size_t	len;

	signe = 0;
	res = 0;
	i = ft_clean(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = 1;
		i++;
	}
	len = ft_strlendigit(str, i) - 1;
	while (ft_isdigit(str[i]))
	{
		if (signe)
			res = res - (str[i] - 48) * ft_power(len - i, 10);
		else
			res = res + (str[i] - 48) * ft_power(len - i, 10);
		i++;
	}
	return (res);
}
