/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 12:59:39 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/26 13:19:37 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static char	*ft_realloc(char *s, size_t size)
{
	char	*ret;

	if (!(ret = ft_strnew(size)))
		return (NULL);
	ret = ft_strcpy(ret, s);
	ft_strdel(&s);
	return (ret);
}

static int	ft_untilc(char *buff, char c)
{
	int	i;

	i = 0;
	while (buff[i] && buff[i] != c)
		i++;
	return (i);
}

static int	get_next_line2(char **next_line, char **line)
{
	char	*tmp;
	int		i;

	i = ft_untilc(*next_line, '\n');
	if (ft_strchr(*next_line, '\n'))
	{
		if (!(*line = ft_realloc(*line, i + ft_strlen(*line))))
		{
			ft_strdel(line);
			return (-1);
		}
		ft_strncat(*line, *next_line, i);
		tmp = ft_strsub(*next_line, i + 1, ft_strlen(*next_line + i + 1));
		ft_strdel(next_line);
		*next_line = ft_strdup(tmp);
		ft_strdel(&tmp);
		return (1);
	}
	if (!(*line = ft_realloc(*line, i + ft_strlen(*line))))
		return (-1);
	ft_strncat(*line, *next_line, i);
	ft_strdel(next_line);
	return (0);
}

static int	get_next_line3(char **buff, char **line, char **next_line)
{
	int	i;

	i = ft_untilc(*buff, '\n');
	if (ft_strchr(*buff, '\n'))
	{
		if (!(*line = ft_realloc(*line, i + ft_strlen(*line))))
			return (-1);
		*line = ft_strncat(*line, *buff, i);
		*next_line = ft_strsub(*buff, i + 1, ft_strlen(*buff + i));
		ft_strdel(buff);
		return (1);
	}
	if (!(*line = ft_realloc(*line, i + ft_strlen(*line))))
		return (-1);
	*line = ft_strncat(*line, *buff, i);
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	char		*buff;
	static char	*next_line = NULL;
	ssize_t		r;

	if (!line || (fd < 0))
		return (-1);
	if (!(*line = ft_strnew(0)))
		return (-1);
	if (next_line && *next_line)
	{
		if ((get_next_line2(&next_line, line)))
			return (1);
	}
	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	while (((r = read(fd, (void *)buff, BUFF_SIZE)) > 0))
	{
		if ((get_next_line3(&buff, line, &next_line)))
			return (1);
		ft_strclr(buff);
	}
	ft_strdel(&buff);
	if (**line)
		return (1);
	return (r);
}
