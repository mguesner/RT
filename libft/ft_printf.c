/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 10:36:39 by mguesner          #+#    #+#             */
/*   Updated: 2014/04/22 11:22:27 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_flag3(char **format, va_list arg)
{
	int	d;

	if ((*(*format + 1) == '-'
				&& ft_is_flag(*(*format + 2))) || *(*format + 1) == '0')
	{
		*format = *format + 1;
		return (ft_put_flag(format, arg));
	}
	if (*(*format + 1) == '+')
	{
		*format = *format + 1;
		if (*(*format + 1) == 'd' || *(*format + 1) == 'i')
		{
			*format = *format + 1;
			d = va_arg(arg, int);
			if (d >= 0)
				return (ft_nputstr("+") + ft_nputnbr(d));
			return (ft_nputnbr(d));
		}
		return (ft_put_flag(format, arg));
	}
	return (ft_put_flag10(format, arg));
}

static int	ft_put_flag2(char **format, va_list arg)
{
	if (*(*format + 1) == 'o')
	{
		*format = *format + 1;
		return (ft_puto(va_arg(arg, unsigned int)));
	}
	if (*(*format + 1) == 'x')
	{
		*format = *format + 1;
		return (ft_putx(va_arg(arg, unsigned int)));
	}
	if (*(*format + 1) == 'p')
	{
		*format = *format + 1;
		return (ft_nputstr("0x") + ft_putp(va_arg(arg, unsigned long)));
	}
	if (*(*format + 1) == '%')
	{
		*format = *format + 1;
		return (ft_nputstr("%"));
	}
	return (ft_put_flag3(format, arg));
}

int			ft_put_flag(char **format, va_list arg)
{
	if (*(*format + 1) == 'd' || *(*format + 1) == 'i')
	{
		*format = *format + 1;
		return (ft_nputnbr(va_arg(arg, int)));
	}
	if (*(*format + 1) == 's')
	{
		*format = *format + 1;
		return (ft_nputstr(va_arg(arg, char *)));
	}
	if (*(*format + 1) == 'c')
	{
		*format = *format + 1;
		ft_putchar(va_arg(arg, int));
		return (1);
	}
	if (*(*format + 1) == 'u')
	{
		*format = *format + 1;
		return (ft_nputunbr(va_arg(arg, unsigned long)));
	}
	return (ft_put_flag2(format, arg));
}

static int	ft_printf2(char *format, va_list arg)
{
	int	res;

	res = 0;
	while (*format)
	{
		if (*format == '%')
			res += ft_put_flag(&format, arg);
		else
		{
			ft_putchar(*format);
			res++;
		}
		format++;
	}
	return (res);
}

int			ft_printf(char *format, ...)
{
	va_list	arg;
	int		res;

	va_start(arg, format);
	res = ft_printf2(format, arg);
	return (res);
}
