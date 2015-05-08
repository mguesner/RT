/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 15:23:38 by mguesner          #+#    #+#             */
/*   Updated: 2013/12/17 15:25:49 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putp(unsigned long n)
{
	int	i;

	i = 0;
	if (n < 16)
	{
		if (n < 10)
			ft_putchar(n + 48);
		else
			ft_putchar(n + 'a' - 10);
		i++;
	}
	else
	{
		i = 1 + i + ft_putp(n / 16);
		if (n % 16 < 10)
			ft_putchar(n % 16 + 48);
		else
			ft_putchar(n % 16 + 'a' - 10);
	}
	return (i);
}
