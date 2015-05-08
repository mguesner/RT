/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_flag01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 16:44:40 by mguesner          #+#    #+#             */
/*   Updated: 2014/04/22 11:26:16 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_flag_d(char **format, va_list arg, int i)
{
	int	d;
	int	ret;

	ret = 0;
	d = va_arg(arg, int);
	i = i - ft_count_digit(d);
	while (i > 0)
	{
		ret = ret + ft_nputstr(" ");
		i--;
	}
	*format = *format + 1;
	ret = ret + ft_nputnbr(d);
	return (ret);
}

int	ft_put_flag_s(char **format, va_list arg, size_t i)
{
	char	*str;
	int		ret;

	ret = 0;
	str = va_arg(arg, char *);
	str = (str ? str : "(null)");
	while (i > 0 && i > ft_strlen(str))
	{
		ret = ret + ft_nputstr(" ");
		i--;
	}
	ret = ret + ft_nputstr(str);
	*format = *format + 1;
	return (ret);
}

int	ft_put_flag_rd(char **format, va_list arg, int i)
{
	int	d;
	int	ret;

	d = va_arg(arg, int);
	i = i + ft_count_digit(d);
	ret = ft_nputnbr(d);
	while (i < 0)
	{
		ret = ret + ft_nputstr(" ");
		i++;
	}
	(*format)++;
	return (ret);
}

int	ft_put_flag10(char **format, va_list arg)
{
	int	i;

	if ((i = ft_atoi(*format + 1)))
		return (ft_put_flag_number(format, arg, i));
	if (*(*format + 1) == '*')
	{
		*format = *format + 1;
		i = va_arg(arg, int);
		return (ft_put_flag_point_star(format, arg, i));
	}
	return (ft_put_flag20(format, arg));
}
