/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 10:28:10 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/11 15:13:04 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <rt.h>

# define OPEN 1
# define CLOSE 0

typedef struct s_pars	t_pars;

typedef void			(*t_f_parse)(char *line, t_pars *e, int *off);

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
	UNKOBJ,
	UNKPARAM,
	SCOPEMISS,
	BADARG,
	NBERR
}						t_err_type;

typedef struct			s_err
{
	t_err_type			err_type;
	char				*where;
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
	char				*err_msg[NBERR];
	t_err_begin			err_list;
	t_step				step;
	int					nb_line;
	int					scope;
	int					err;
	t_obj_list_begin	obj_lst;
	t_obj				*cur;
};

void					parser(char *file_name);
void					add_obj_lst(t_obj_list_begin *begin, t_obj *elem);
void					init_pars(t_pars *e);
void					check_line(char *line, t_pars *e);
void					add_err(t_pars *e, t_err_type err, char *line);
void					check_pars_err(t_pars e);

void					p_begin(char *line, t_pars *e, int *off);

void					p_camera(char *line, t_pars *e, int *off);

void					cam_loc(char *line, t_pars *e, int *off);
void					cam_look_at(char *line, t_pars *e, int *off);

void					p_spot(char *line, t_pars *e, int *off);

void					spot_loc(char *line, t_pars *e, int *off);
void					spot_color(char *line, t_pars *e, int *off);

#endif
