/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_flag_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 17:32:01 by mguesner          #+#    #+#             */
/*   Updated: 2014/04/22 18:41:56 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_flag_x(char **format, va_list arg, int i)
{
	unsigned int	x;
	int				ret;

	x = va_arg(arg, unsigned int);
	i = i - ft_count_xdigit(x);
	ret = 0;
	while (i > 0)
	{
		ret = ret + ft_nputstr(" ");
		i--;
	}
	(*format)++;
	return (ret + ft_putx(x));
}

int	ft_put_flag_rx(char **format, va_list arg, int i)
{
	unsigned int	x;
	int				ret;

	x = va_arg(arg, unsigned int);
	i = i + ft_count_xdigit(x);
	ret = ft_putx(x);
	while (i < 0)
	{
		ret = ret + ft_nputstr(" ");
		i++;
	}
	(*format)++;
	return (ret);
}

int	ft_put_flag_point_star_x(char **format, va_list arg, int i)
{
	unsigned long long	x;
	int					ret;

	x = va_arg(arg, unsigned long long);
	i = i - ft_count_xdigit(x);
	ret = 0;
	while (i > 0)
	{
		ret = ret + ft_nputstr("0");
		i--;
	}
	(*format)++;
	return (ret + ft_putx(x));
}
