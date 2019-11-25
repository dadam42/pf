#ifndef T_STR_ITERATOR_UTIL_H
# define T_STR_ITERATOR_UTIL_H
# define T_STR_ITERATOR_METHODS {{.next = fwd_next ,.prev = bwd_next,\
								.step = fwd_step, .init = fwd_init},\
								{.next = bwd_next ,.prev = fwd_next,\
								.step = bwd_step, .init = bwd_init}}
# include "t_str_iterator.h"

char	*fwd_step(t_str_iterator *it, int s);
char	*bwd_step(t_str_iterator *it, int s);
char	*fwd_next(t_str_iterator *it);
char	*bwd_next(t_str_iterator *it);
void	fwd_init(t_str_iterator *it);
void	bwd_init(t_str_iterator *it);

typedef struct	s_str_iterator_methods
{
	char	*(*next)(t_str_iterator *it);
	char	*(*prev)(t_str_iterator *it);
	char	*(*step)(t_str_iterator *it, int s);
	void	(*init)(t_str_iterator *it);
}				t_str_iterator_methods;
#endif
