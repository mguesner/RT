#include <parser.h>

void					p_triangle(t_pars *e, t_lex **node)
{
	t_fptoken		tools[NBTOKEN];

	tools[WORD] = &p_plane_word;
//	tools[VALUE] = &p_plane_value;
	tools[OPENSCOPE] = &p_openscope;
	tools[CLOSESCOPE] = &p_closescope;
	tools[VECTOR] = &p_triangle_vector;
	tools[(*node)->token_type](e, node);
}