/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 16:59:34 by mguesner          #+#    #+#             */
/*   Updated: 2014/04/22 18:03:02 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_digit(int n)
{
	int	ret;

	ret = 1;
	if (n < 0)
		ret++;
	while (n > 9 || n < -9)
	{
		ret++;
		n = n / 10;
	}
	return (ret);
}

int	ft_count_odigit(unsigned int o)
{
	int	ret;

	ret = 1;
	while (o > 7)
	{
		ret++;
		o = o / 8;
	}
	return (ret);
}

int	ft_count_xdigit(unsigned long long x)
{
	int	ret;

	ret = 1;
	while (x > 15)
	{
		ret++;
		x = x / 16;
	}
	return (ret);
}
