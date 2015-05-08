/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 13:22:25 by mguesner          #+#    #+#             */
/*   Updated: 2013/12/17 12:32:29 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nputstr(const char *str)
{
	int	i;

	if (!str)
		return (ft_nputstr("(null)"));
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
