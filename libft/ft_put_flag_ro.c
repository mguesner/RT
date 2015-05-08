/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_flag_ro.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 12:57:54 by mguesner          #+#    #+#             */
/*   Updated: 2013/12/22 17:31:42 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_flag_ro(char **format, va_list arg, int i)
{
	unsigned int	o;
	int				ret;

	o = va_arg(arg, unsigned int);
	i = i + ft_count_odigit(o);
	ret = ft_puto(o);
	while (i < 0)
	{
		ret = ret + ft_nputstr(" ");
		i++;
	}
	(*format)++;
	return (ret);
}

int	ft_put_flag_point_star_o(char **format, va_list arg, int i)
{
	unsigned int	o;
	int				ret;

	o = va_arg(arg, unsigned int);
	(*format)++;
	if (!o && !i)
		return (0);
	i = i - ft_count_odigit(o);
	ret = 0;
	while (i > 0)
	{
		ret = ret + ft_nputstr("0");
		i--;
	}
	return (ret + ft_puto(o));
}

int	ft_put_flag_point_star_d(char **format, va_list arg, int i)
{
	int	d;
	int	ret;

	d = va_arg(arg, int);
	(*format)++;
	if (!d && !i)
		return (0);
	i = i - ft_count_digit(ft_abs(d));
	ret = (d < 0 ? ft_nputstr("-") : 0);
	while (i > 0)
	{
		ret = ret + ft_nputstr("0");
		i--;
	}
	return (ret + ft_nputnbrabs(d));
}

int	ft_put_flag_number(char **format, va_list arg, int i)
{
	int	ret;

	ret = 0;
	while ((*(*format + 1) >= '0' && *(*format + 1) <= '9')
			|| *(*format + 1) == '-')
		*format = *format + 1;
	if (*(*format + 1) == 'd' || *(*format + 1) == 'i')
		return (ft_put_flag_d(format, arg, i));
	else if (*(*format + 1) == 's')
		return (ft_put_flag_s(format, arg, i));
	else if (*(*format + 1) == 'c')
		return (ft_put_flag_c(format, arg, i));
	else if (*(*format + 1) == 'u')
		return (ft_put_flag_u(format, arg, i));
	else if (*(*format + 1) == 'o')
		return (ft_put_flag_o(format, arg, i));
	else if (*(*format + 1) == 'x')
		return (ft_put_flag_x(format, arg, i));
	while (i - 1 > 0)
	{
		ret = ret + ft_nputstr(" ");
		i--;
	}
	return (ret);
}
