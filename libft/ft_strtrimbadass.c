/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimbadass.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 15:10:13 by mguesner          #+#    #+#             */
/*   Updated: 2015/01/30 11:07:34 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtrimbadass(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ft_isblank(str[i]))
		i++;
	while (str[i])
	{
		str[j] = str[i];
		i++;
		j++;
	}
	str[j] = 0;
	j--;
	while (j >= 0 && ft_isblank(str[j]))
	{
		str[j] = 0;
		j--;
	}
}
