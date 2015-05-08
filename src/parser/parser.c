/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 10:39:28 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/08 14:52:17 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <fcntl.h>
#include <errno.h>

void	parser(char *file_name)
{
	int		fd;
	char	*line;
	t_pars	e;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		error(errno);
	init_pars(&e);
	while (get_next_line(fd, &line) > 0)
	{
		// check_line(line, &e);
		ft_strdel(&line);
		e.nb_line++;
	}
}
