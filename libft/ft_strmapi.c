/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:46:25 by mguesner          #+#    #+#             */
/*   Updated: 2013/12/01 10:16:28 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	i = 0;
	if (!s || !f)
		return (NULL);
	res = ft_strnew(ft_strlen(s));
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}
