/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 11:39:48 by mguesner          #+#    #+#             */
/*   Updated: 2013/12/20 10:31:05 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_abs(int n)
{
	if (n > 0)
		return (n);
	return (-1 * n);
}

int	ft_nputnbr(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		ft_putchar('-');
	}
	if (n < 10 && n > -10)
	{
		ft_putchar(ft_abs(n) + 48);
		i++;
	}
	else
	{
		i = 1 + i + ft_nputnbr(ft_abs(n / 10));
		ft_putchar(ft_abs(n % 10) + 48);
	}
	return (i);
}

int	ft_nputnbrabs(int n)
{
	int	i;

	i = 0;
	if (n < 10 && n > -10)
	{
		ft_putchar(ft_abs(n) + 48);
		i++;
	}
	else
	{
		i = 1 + i + ft_nputnbr(ft_abs(n / 10));
		ft_putchar(ft_abs(n % 10) + 48);
	}
	return (i);
}
