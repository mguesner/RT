/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:24:02 by mguesner          #+#    #+#             */
/*   Updated: 2013/12/01 10:24:42 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*res;

	if (!s || !f)
		return (NULL);
	res = ft_strnew(ft_strlen(s) + 1);
	i = 0;
	while (s[i])
	{
		res[i] = f(s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}
