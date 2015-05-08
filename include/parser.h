/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 10:28:10 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/08 13:55:34 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_pars	t_pars;

typedef void			(*t_f_parse)(char *line, t_pars *e);

typedef enum			e_step
{
	PBEGIN,
	PCAMERA,
	PSPOT,
	PPLANE,
	PSPHERE,
	PCYLINDER,
	PCYLINDER42,
	PCONE,
	PCONNE42,
	NBSTEP
}						t_step;

typedef enum			e_err_type
{
	UNKSYMB,
	PARSE
}						t_err_type;

typedef struct			s_err
{
	t_err_type			err_type;
	int					line;
	struct s_err		*next;
}						t_err;

typedef struct			s_err_begin
{
	struct s_err		*begin;
	struct s_err		*end;
	int					size;
}						t_err_begin;

struct					s_pars
{
	t_f_parse			tools[NBSTEP];
	t_err_begin			err_list;
	t_step				step;
	int					nb_line;
};

void					parser(char *file_name);
void					init_pars(t_pars *e);
void					check_line(char *line, t_pars *e);
void					add_err(t_pars *e, t_err_type err);

void					p_begin(char *line, t_pars *e);

#endif
