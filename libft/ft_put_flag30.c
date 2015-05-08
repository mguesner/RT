/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_flag30.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 09:43:13 by mguesner          #+#    #+#             */
/*   Updated: 2013/12/22 18:49:44 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_space_u(char **format, va_list arg)
{
	unsigned int	d;

	d = va_arg(arg, unsigned int);
	(*format)++;
	return (ft_nputunbr(d));
}

int	ft_put_flag31(char **format, va_list arg)
{
	if (*(*format + 1) == '.')
		return (ft_put_flag_point(format, arg));
	if (*(*format + 1) == '#')
	{
		(*format)++;
		if (*(*format + 1) == 'x')
			return (ft_nputstr("0x") + ft_put_flag(format, arg));
		if (*(*format + 1) == 'o')
			return (ft_nputstr("0") + ft_put_flag(format, arg));
	}
	return (0);
}

int	ft_put_flag32(char **format, va_list arg)
{
	if (*(*format + 1) == 's')
	{
		(*format)++;
		return (ft_nputstr(va_arg(arg, char *)));
	}
	return (ft_put_flag31(format, arg));
}

int	ft_put_flag30(char **format, va_list arg)
{
	int	i;
	int	d;

	i = ft_skip(format);
	if (i)
	{
		if (*(*format + 1) == 'd' || *(*format + 1) == 'i')
		{
			d = va_arg(arg, int);
			(*format)++;
			if (d >= 0)
				return (ft_nputstr(" ") + ft_nputnbr(d));
			return (ft_nputnbr(d));
		}
		else if (*(*format + 1) == 'u')
			return (ft_put_space_u(format, arg));
		return (ft_put_flag(format, arg));
	}
	return (ft_put_flag32(format, arg));
}
