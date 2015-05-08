/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_flag_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 12:00:28 by mguesner          #+#    #+#             */
/*   Updated: 2014/04/22 11:31:23 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_flag_point_s(char **format, va_list arg, int i)
{
	char	*str;
	int		ret;

	ret = 0;
	str = va_arg(arg, char *);
	str = (str ? str : "(null)");
	(*format)++;
	while (i > 0 && *str)
	{
		ft_putchar(*str);
		ret++;
		str++;
		i--;
	}
	return (ret);
}

int	ft_put_flag_rs(char **format, va_list arg, int i)
{
	char	*str;
	int		ret;

	str = va_arg(arg, char *);
	str = (str ? str : "(null)");
	ret = ft_nputstr(str);
	while (i < 0 && i < -1 * (int)ft_strlen(str))
	{
		ret = ret + ft_nputstr(" ");
		i++;
	}
	(*format)++;
	return (ret);
}

int	ft_put_flag_c(char **format, va_list arg, int i)
{
	int	d;
	int	ret;

	ret = 0;
	d = va_arg(arg, int);
	i--;
	while (i > 0)
	{
		ret = ret + ft_nputstr(" ");
		i--;
	}
	(*format)++;
	ft_putchar(d);
	ret++;
	return (ret);
}

int	ft_put_flag_rc(char **format, va_list arg, int i)
{
	int	d;
	int	ret;

	ret = 1;
	d = va_arg(arg, int);
	ft_putchar(d);
	i++;
	while (i < 0)
	{
		ret = ret + ft_nputstr(" ");
		i++;
	}
	(*format)++;
	return (ret);
}

int	ft_put_flag_point_star_s(char **format, va_list arg, int i)
{
	if (i >= 0)
		return (ft_put_flag_point_s(format, arg, i));
	(*format)++;
	return (ft_nputstr(va_arg(arg, char *)));
}
