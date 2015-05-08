/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:53:19 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/10 11:52:15 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;

	if ((res = (char *)ft_memalloc(size + 1)))
	{
		ft_bzero(res, size + 1);
		return (res);
	}
	else
		return (NULL);
}
