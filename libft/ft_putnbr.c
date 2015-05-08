/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:27:49 by mguesner          #+#    #+#             */
/*   Updated: 2013/12/01 10:18:52 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr2(int n)
{
	if (n < 10)
	{
		ft_putchar(n + 48);
	}
	else
	{
		ft_putnbr2(n / 10);
		ft_putchar((n % 10) + 48);
	}
}

void		ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr2(n * -1);
	}
	else
	{
		ft_putnbr2(n);
	}
}
