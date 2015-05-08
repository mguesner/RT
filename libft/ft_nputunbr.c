/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nputunbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:58:08 by mguesner          #+#    #+#             */
/*   Updated: 2014/04/16 14:47:33 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nputunbr(unsigned long n)
{
	int	i;

	i = 0;
	if (n < 10)
	{
		ft_putchar(n + 48);
		i++;
	}
	else
	{
		i = 1 + i + ft_nputnbr(n / 10);
		ft_putchar(n % 10 + 48);
	}
	return (i);
}
