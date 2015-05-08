/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:41:51 by mguesner          #+#    #+#             */
/*   Updated: 2014/02/02 08:43:34 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t		i;
	char		*temp1;
	char		*temp2;

	if (!s1 || !s2)
		return (NULL);
	temp1 = (char *)s1;
	temp2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)temp2[i] == (unsigned char)c)
		{
			temp1[i] = temp2[i];
			return (&temp1[i + 1]);
		}
		temp1[i] = temp2[i];
		i++;
	}
	return (NULL);
}
