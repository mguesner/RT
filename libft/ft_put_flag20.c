/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_flag20.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 14:18:35 by mguesner          #+#    #+#             */
/*   Updated: 2014/04/26 15:43:41 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_flag22(char **format, va_list arg)
{
	int	i;

	if (*(*format + 1) == '.' && *(*format + 2) == '*')
	{
		i = va_arg(arg, int);
		*format = *format + 2;
		if (*(*format + 1) == 'd' || *(*format + 1) == 'i')
			return (ft_put_flag_point_star_d(format, arg, i));
		else if (*(*format + 1) == 's')
			return (ft_put_flag_point_star_s(format, arg, i));
		else if (*(*format + 1) == 'u')
			return (ft_put_flag_point_star_u(format, arg, i));
		else if (*(*format + 1) == 'o')
			return (ft_put_flag_point_star_o(format, arg, i));
		else if (*(*format + 1) == 'x')
			return (ft_put_flag_point_star_x(format, arg, i));
		return (ft_put_flag(format, arg));
	}
	return (ft_put_flag30(format, arg));
}

static int	ft_put_flag_point_star_w(char **format, va_list arg, int i)
{
	unsigned int		x;
	int					ret;

	x = va_arg(arg, unsigned int);
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

static int	ft_put_flag21(char **format, va_list arg)
{
	int	i;

	if (*(*format + 1) == '.' && (i = ft_atoi(*format + 2)))
	{
		*format = *format + 1;
		while (ft_isdigit(*(*format + 1)))
			*format = *format + 1;
		if ((*(*format + 1) == 'd' || *(*format + 1) == 'i') && i >= 0)
			return (ft_put_flag_point_star_d(format, arg, i));
		else if (*(*format + 1) == 's')
			return (ft_put_flag_point_s(format, arg, i));
		else if (*(*format + 1) == 'u')
			return (ft_put_flag_point_star_u(format, arg, i));
		else if (*(*format + 1) == 'o')
			return (ft_put_flag_point_star_o(format, arg, i));
		else if (*(*format + 1) == 'x')
			return (ft_put_flag_point_star_x(format, arg, i));
		else if (*(*format + 1) == 'w')
			return (ft_put_flag_point_star_w(format, arg, i));
		return (ft_put_flag(format, arg));
	}
	return (ft_put_flag22(format, arg));
}

int			ft_put_flag20(char **format, va_list arg)
{
	int	d;

	if (*(*format + 1) == '.' && (((*(*format + 2) == 'd'
						|| *(*format + 2) == 'i'))
				|| (*(*format + 2) == '0' && (*(*format + 3) == 'd'
						|| *(*format + 3) == 'i'))))
	{
		d = va_arg(arg, int);
		if (*(*format + 2) == '0')
			*format = *format + 3;
		else
			*format = *format + 2;
		if (d != 0)
			return (ft_nputnbr(d));
		return (0);
	}
	return (ft_put_flag21(format, arg));
}
