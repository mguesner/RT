/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_flag_point_star.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 14:55:55 by mguesner          #+#    #+#             */
/*   Updated: 2013/12/22 18:11:49 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_flag_point_star2(char **format, va_list arg, int i)
{
	if (*(*format + 1) == 'o')
	{
		if (i >= 0)
			return (ft_put_flag_o(format, arg, i));
		return (ft_put_flag_ro(format, arg, i));
	}
	if (*(*format + 1) == 'x')
	{
		if (i >= 0)
			return (ft_put_flag_x(format, arg, i));
		return (ft_put_flag_rx(format, arg, i));
	}
	return (0);
}

int	ft_put_flag_point_star(char **format, va_list arg, int i)
{
	if (*(*format + 1) == 'd' || *(*format + 1) == 'i')
	{
		if (i >= 0)
			return (ft_put_flag_d(format, arg, i));
		return (ft_put_flag_rd(format, arg, i));
	}
	else if (*(*format + 1) == 'c')
	{
		if (i >= 0)
			return (ft_put_flag_c(format, arg, i));
		return (ft_put_flag_rc(format, arg, i));
	}
	else if (*(*format + 1) == 's')
	{
		if (i >= 0)
			return (ft_put_flag_s(format, arg, i));
		return (ft_put_flag_rs(format, arg, i));
	}
	else if (*(*format + 1) == 'u')
	{
		if (i >= 0)
			return (ft_put_flag_u(format, arg, i));
		return (ft_put_flag_ru(format, arg, i));
	}
	return (ft_put_flag_point_star2(format, arg, i));
}

int	ft_put_flag_point2(char **format, va_list arg)
{
	unsigned int	o;

	if (*(*format + 1) == 'o')
	{
		(*format)++;
		o = va_arg(arg, unsigned int);
		if (o)
			return (ft_puto(o));
	}
	return (0);
}

int	ft_put_flag_point(char **format, va_list arg)
{
	unsigned int	u;

	(*format)++;
	if (*(*format + 1) == '0')
		(*format)++;
	if (*(*format + 1) == 'c')
	{
		(*format)++;
		ft_putchar(va_arg(arg, int));
		return (1);
	}
	if (*(*format + 1) == 's')
		(*format)++;
	if (*(*format + 1) == 'u')
	{
		(*format)++;
		u = va_arg(arg, unsigned int);
		if (u)
			return (ft_nputunbr(u));
	}
	return (ft_put_flag_point2(format, arg));
}
