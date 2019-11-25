#ifndef T_STR_ITERATOR_H
# define T_STR_ITERATOR_H
# define T_STR_ITERATOR_BWD 0
# define T_STR_ITERATOR_FWD 1

struct					s_string;
typedef struct s_string	t_string;
typedef short			t_str_iterator_type;


typedef struct s_str_iterator t_str_iterator;

struct					s_str_iterator
{
	t_string 					*str;
	t_str_iterator_type			type;
	char						*ref;
	char						*(*next)(t_str_iterator *it);
	char						*(*prev)(t_str_iterator *it);
	char						*(*step)(t_str_iterator *it, int s);
	void						(*init)(t_str_iterator *it);
};

void							t_str_iterator_init(t_str_iterator *it,
													t_string *str,
													t_str_iterator_type type);
t_str_iterator	*new_str_iterator(t_string *str, t_str_iterator_type type);
void							destroy_str_iterator(t_str_iterator *const it);
#endif
