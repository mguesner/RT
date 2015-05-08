/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 09:26:46 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/26 13:17:41 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(s1);
	if ((res = ft_strnew(size)))
	{
		while (i < size)
		{
			res[i] = s1[i];
			i++;
		}
		res[i] = 0;
		return (res);
	}
	return (NULL);
}
