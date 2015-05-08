/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:10:49 by mguesner          #+#    #+#             */
/*   Updated: 2013/12/01 10:10:54 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if ((!s1 && !s2))
		return (NULL);
	while (s2[i] && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	while (i < n)
	{
		s1[i] = 0;
		i++;
	}
	return (s1);
}
