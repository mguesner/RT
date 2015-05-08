/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:36:19 by mguesner          #+#    #+#             */
/*   Updated: 2013/12/01 10:13:47 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(res = ft_strnew(len + 1)))
		return (NULL);
	while (i < len)
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = 0;
	return (res);
}
