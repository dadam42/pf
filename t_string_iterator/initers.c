#include "t_str_iterator.h"
#include "util.h"
#include <stdlib.h>

void			t_str_iterator_init(t_str_iterator *it, t_string *str,
									t_str_iterator_type type)
{
	static t_str_iterator_methods methods[] = T_STR_ITERATOR_METHODS;

	it->str = str;
	it->type = type;
	it->next = methods[it->type].next;
	it->prev = methods[it->type].prev;
	it->step = methods[it->type].step;
	it->init = methods[it->type].init;
	it->init(it);
}

t_str_iterator	*new_str_iterator(t_string *str, t_str_iterator_type type)
{
	t_str_iterator *new;

	if ((new = malloc(sizeof(t_str_iterator))))
		t_str_iterator_init(new, str, type);
	return (new);
}

void			destroy_str_iterator(t_str_iterator *it)
{
	free(it);
}
