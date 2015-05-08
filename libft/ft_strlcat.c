/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:00:58 by mguesner          #+#    #+#             */
/*   Updated: 2015/01/26 15:56:45 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	res;
	size_t	i;
	size_t	j;

	j = 0;
	res = (ft_strlen(src) + ft_strlen(dst));
	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	if (size - i == 0)
		return (i + ft_strlen(src));
	while (src[j] && ((i + j) < (size - 1)))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = 0;
	return (res);
}
