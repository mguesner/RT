/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:58:37 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/26 13:18:51 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countnoblank(char const *s)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (ft_isblank(s[i]))
		i++;
	while (s[i])
	{
		i++;
		res++;
	}
	while (ft_isblank(s[i - 1]) && res)
	{
		i--;
		res--;
	}
	return (res);
}

char		*ft_strtrim(char const *s)
{
	char	*res;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = ft_countnoblank(s);
	i = 0;
	if (!(res = (char *)ft_memalloc((unsigned int)len + 1)))
		return (NULL);
	while (ft_isblank(*s))
		s++;
	while (len-- > 0)
	{
		res[i] = *s;
		s++;
		i++;
	}
	res[i] = 0;
	return (res);
}
