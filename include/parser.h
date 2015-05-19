/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 10:28:10 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/19 15:09:51 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <rt.h>

typedef struct s_pars	t_pars;


typedef enum			e_token
{
	WORD,
	VALUE,
	OPENSCOPE,
	CLOSESCOPE,
	VECTOR,
	NBTOKEN
}						t_token;

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
	PCONE42,
	NBSTEP
}						t_step;

typedef enum			e_substep
{
	SSBEGIN,
	SSPIGMENT,
	SSTEXTURE,
	NBSUBSTEP
}						t_substep;

typedef enum			e_err_type
{
	UNKSYMB,
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
	t_err				*begin;
	t_err				*end;
	int					size;
}						t_err_begin;

typedef struct			s_lex
{
	t_token				token_type;
	char				*value;
	int					line;
	struct s_lex		*next;
}						t_lex;

typedef struct			s_lex_begin
{
	t_lex				*begin;
	t_lex				*end;
	int					size;
}						t_lex_begin;

typedef void			(*t_f_parse)(t_pars *e, t_lex **node);
typedef void			(*t_fptoken)(t_pars *e, t_lex **node);

struct					s_pars
{
	void				*mlx;
	t_f_parse			tools[NBSTEP];
	char				*err_msg[NBERR];
	t_err_begin			err_list;
	t_lex_begin			lex_lst;
	t_obj_list_begin	obj_lst;
	t_step				step;
	t_substep			substep;
	int					nb_line;
	int					scope;
	int					err;
	int					nb_vector;
	int					nb_value;
	t_obj				*cur;
};

void					lex_pars(char *file_name, t_libx *mlx);
void					init_pars(t_pars *e);
void					clean_pars(t_pars *e);

void					lexer(int fd, t_pars *e);
void					add_lex_node(t_lex_begin *begin, t_token token, char *value, int line);
void					lex_word(char *line, t_pars *e, int *offset, int size);
void					lex_value(char *line, t_pars *e, int *offset, int size);
void					lex_vec(char *line, t_pars *e, int *offset, int size);

void					add_obj_lst(t_obj_list_begin *begin, t_obj *elem);
void					add_err(t_pars *e, t_err_type err, char *line);

void					parser(t_pars *e);

void					fill_vector(t_pars *e, char *value, t_vec *vec);
void					p_openscope(t_pars *e, t_lex **node);
void					p_closescope(t_pars *e, t_lex **node);
void					p_pigment(t_pars *e, t_lex **node);
void					p_texture(t_pars *e, t_lex **node);
t_texture				texture_init(t_pars *e, char *name);

void					p_begin(t_pars *e, t_lex **node);

void					p_begin_word(t_pars *e, t_lex **node);
void					add_error_begin(t_pars *e, t_lex **node);

void					p_camera(t_pars *e, t_lex **node);

void					p_camera_word(t_pars *e, t_lex **node);
void					cam_loc(t_pars *e, t_lex **node);
void					cam_look_at(t_pars *e, t_lex **node);
void					add_error_camera(t_pars *e, t_lex **node);

void					p_spot(t_pars *e, t_lex **node);

void					p_spot_word(t_pars *e, t_lex **node);

void					color(t_pars *e, t_lex **node);

void					p_plane(t_pars *e, t_lex **node);

void					p_plane_word(t_pars *e, t_lex **node);
void					p_plane_value(t_pars *e, t_lex **node);
void					p_plane_vector(t_pars *e, t_lex **node);

void					p_sphere(t_pars *e, t_lex **node);

void					p_sphere_value(t_pars *e, t_lex **node);
void					p_sphere_vector(t_pars *e, t_lex **node);

void					p_cylinder42(t_pars *e, t_lex **node);

void					p_cylinder42_vector(t_pars *e, t_lex **node);

void					p_cone42(t_pars *e, t_lex **node);

void					check_pars_err(t_pars e);

#endif
