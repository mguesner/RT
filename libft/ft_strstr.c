/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:55:14 by mguesner          #+#    #+#             */
/*   Updated: 2013/12/01 10:15:59 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		len;
	char	*res;

	len = ft_strlen(s2);
	res = (char *)s1;
	if (!*s2)
		return (res);
	while (*res)
	{
		if (!(ft_memcmp(res, s2, len)))
			return (res);
		res++;
	}
	return (NULL);
}
