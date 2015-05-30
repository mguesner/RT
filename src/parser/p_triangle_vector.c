#include <parser.h>

void					p_triangle_vector(t_pars *e, t_lex **node)
{
	t_vec	v;

	fill_vector(e, (*node)->value, &v);
	if (!e->nb_vector && e->cur)
		e->cur->coord = *((t_point *)&v);
	else if (e->nb_vector == 1 && e->cur)
		((t_triangle *)e->cur)->u = *(&v);
	else if (e->cur)
		((t_triangle *)e->cur)->v = *(&v);
	e->nb_vector++;
}