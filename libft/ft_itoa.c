/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:42:23 by mguesner          #+#    #+#             */
/*   Updated: 2014/01/26 08:47:44 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countnumber(int n)
{
	int	res;

	res = 1;
	while (n < -9 || n > 9)
	{
		res++;
		n = n / 10;
	}
	if (n >= 0)
		return (res);
	else
		return (res + 1);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		nvalue;

	nvalue = n;
	i = ft_countnumber(n);
	res = ft_strnew(i + 1);
	while (i--)
	{
		res[i] = ((n < 0) ? (((n % 10) * -1) + 48) : ((n % 10) + 48));
		n = n / 10;
	}
	if (nvalue < 0)
		res[0] = '-';
	return (res);
}
