/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_flag_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 13:41:08 by mguesner          #+#    #+#             */
/*   Updated: 2013/12/22 15:17:25 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_udigit(unsigned int n)
{
	int	ret;

	ret = 1;
	while (n > 9)
	{
		ret++;
		n = n / 10;
	}
	return (ret);
}

int	ft_put_flag_u(char **format, va_list arg, int i)
{
	unsigned int	u;
	int				ret;

	u = va_arg(arg, unsigned int);
	i = i - ft_count_udigit(u);
	ret = 0;
	while (i > 0)
	{
		ret = ret + ft_nputstr(" ");
		i--;
	}
	*format = *format + 1;
	return (ret + ft_nputunbr(u));
}

int	ft_put_flag_ru(char **format, va_list arg, int i)
{
	unsigned int	u;
	int				ret;

	u = va_arg(arg, unsigned int);
	i = i + ft_count_udigit(u);
	ret = ft_nputunbr(u);
	while (i < 0)
	{
		ret = ret + ft_nputstr(" ");
		i++;
	}
	*format = *format + 1;
	return (ret);
}

int	ft_put_flag_point_star_u(char **format, va_list arg, int i)
{
	int				ret;
	unsigned int	u;

	u = va_arg(arg, unsigned int);
	(*format)++;
	if (!i && !u)
		return (0);
	i = i - ft_count_udigit(u);
	ret = 0;
	while (i > 0)
	{
		ret = ret + ft_nputstr("0");
		i--;
	}
	return (ret + ft_nputunbr(u));
}

int	ft_put_flag_o(char **format, va_list arg, int i)
{
	unsigned int	o;
	int				ret;

	o = va_arg(arg, unsigned int);
	i = i - ft_count_odigit(o);
	ret = 0;
	while (i > 0)
	{
		ret = ret + ft_nputstr(" ");
		i--;
	}
	(*format)++;
	return (ret + ft_puto(o));
}
