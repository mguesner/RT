/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:11:11 by mguesner          #+#    #+#             */
/*   Updated: 2013/12/01 10:51:42 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*res;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = n - (int)ft_strlen(s2);
	res = (char *)s1;
	if (!*s2)
		return (res);
	else if (i < 0)
		return (NULL);
	if (!(ft_strncmp(res, s2, n)))
		return (res);
	while (*res && i-- >= 0)
	{
		if (!(ft_memcmp(res, s2, ft_strlen(s2))))
			return (res);
		res++;
	}
	return (NULL);
}
