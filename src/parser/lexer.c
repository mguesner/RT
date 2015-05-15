/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 09:15:08 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/13 12:41:23 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <errno.h>

void		lexer(int fd, t_pars *e)
{
	struct stat		buf;
	char			*file;
	int				offset;
	int				size;

	file = NULL;
	if (fstat(fd, &buf) || (file = mmap(0, buf.st_size, PROT_READ
		, MAP_SHARED, fd, 0)) == MAP_FAILED)
		error(errno);
	size = buf.st_size;
	offset = 0;
	while (offset < size)
	{
		while (offset < size && (*(file + offset) == ' ' || *(file + offset) == '\t'))
			offset++;
		if (offset < size && *(file + offset) == '\n' && ++offset)
			e->nb_line++;
		else if (offset < size && ft_isalpha(*(file + offset)))
			lex_word(file, e, &offset, size);
		else if (offset < size && ft_isdigit(*(file + offset)))
			lex_value(file, e, &offset, size);
		else if (offset < size && *(file + offset) == '{' && offset++)
			add_lex_node(&e->lex_lst, OPENSCOPE, ft_strdup("{"));
		else if (offset < size && *(file + offset) == '}' && offset++)
			add_lex_node(&e->lex_lst, CLOSESCOPE, ft_strdup("}"));
		else if (offset < size && *(file + offset) == '<')
			lex_vec(file, e, &offset, size);
		else if (offset < size && *(file + offset) == ',')
			offset++;
		else if (offset + 1 < size && !ft_strncmp(file + offset, "//", 2) && (offset += 2))
			while (offset < size && *(file + offset) != '\n')
				offset++;
		else
		{
			ft_printf("error : %c\n", *(file + offset));
			break ;
		}
	}
	if (munmap(file, buf.st_size + 1) == -1 || close(fd))
		error(errno);
}