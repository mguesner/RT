/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 17:55:55 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/04 17:48:47 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char *str, char c)
{
	size_t	len;
	char	*ret;

	len = ft_strlen(str) - 1;
	ret = ft_strdup(str);
	while (ret[len] && len > 0 && ret[len] != c)
	{
		len--;
	}
	ret[len] = 0;
	return (ret);
}
