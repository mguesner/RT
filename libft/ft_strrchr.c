/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:51:02 by mguesner          #+#    #+#             */
/*   Updated: 2013/12/01 13:32:29 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	char	*str;

	str = (char *)s;
	res = NULL;
	if (!s)
		return (res);
	while (*str)
	{
		if (*str == (char)c)
			res = str;
		str++;
	}
	if (!(char)c)
		res = str;
	return (res);
}
