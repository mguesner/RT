/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 10:37:35 by mguesner          #+#    #+#             */
/*   Updated: 2014/04/26 15:44:36 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include "libft.h"

int		ft_printf(char *format, ...);
int		ft_nputstr(const char *str);
int		ft_nputnbr(int n);
int		ft_nputunbr(unsigned long n);
int		ft_puto(unsigned int n);
int		ft_putx(unsigned long long n);
int		ft_putp(unsigned long n);
int		ft_skip(char **format);
int		ft_put_flag10(char **format, va_list arg);
int		ft_count_digit(int n);
int		ft_atoi(const char *s);
int		ft_isblank(const char i);
int		ft_isdigit(int i);
size_t	ft_strlen(const char *s);
int		ft_put_flag20(char **format, va_list arg);
int		ft_abs(int n);
int		ft_put_flag30(char **format, va_list arg);
int		ft_nputnbrabs(int n);
int		ft_is_flag(char c);
int		ft_put_flag_c(char **format, va_list arg, int i);
int		ft_put_flag_rc(char **format, va_list arg, int i);
int		ft_put_flag_rs(char **format, va_list arg, int i);
int		ft_put_flag_point_s(char **format, va_list arg, int i);
int		ft_put_flag_point_star_s(char **format, va_list arg, int i);
int		ft_put_flag_u(char **format, va_list arg, int i);
int		ft_put_flag_ru(char **format, va_list arg, int i);
int		ft_put_flag_point_star_u(char **format, va_list arg, int i);
int		ft_put_flag(char **format, va_list arg);
int		ft_put_flag_o(char **format, va_list arg, int i);
int		ft_count_odigit(unsigned int o);
int		ft_put_flag_ro(char **format, va_list arg, int i);
int		ft_put_flag_point_star_o(char **format, va_list arg, int i);
int		ft_put_flag_point_star_d(char **format, va_list arg, int i);
int		ft_put_flag_number(char **format, va_list arg, int i);
int		ft_put_flag_d(char **format, va_list arg, int i);
int		ft_put_flag_s(char **format, va_list arg, size_t i);
int		ft_put_flag_point_star(char **format, va_list arg, int i);
int		ft_put_flag_rd(char **format, va_list arg, int i);
int		ft_put_flag_point(char **format, va_list arg);
int		ft_count_xdigit(unsigned long long x);
int		ft_put_flag_x(char **format, va_list arg, int i);
int		ft_put_flag_rx(char **format, va_list arg, int i);
int		ft_put_flag_point_star_x(char **format, va_list arg, int i);

#endif
