/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:57:33 by mguesner          #+#    #+#             */
/*   Updated: 2013/12/01 10:15:22 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd2(int n, int fd)
{
	if (n < 10)
	{
		ft_putchar_fd(n + 48, fd);
	}
	else
	{
		ft_putnbr_fd2(n / 10, fd);
		ft_putchar_fd((n % 10) + 48, fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd2(n * -1, fd);
	}
	else
	{
		ft_putnbr_fd2(n, fd);
	}
}
