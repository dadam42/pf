#ifndef T_STRING_H
# define T_STRING_H
# ifndef T_STRING_INIT_SIZE
#  define T_STRING_INIT_SIZE 64
# endif
# define T_STRING_INIT_OK 1
# define T_STRING_INIT_ERROR 0
# include <stddef.h>

typedef struct	s_string
{
	char		*start;
	char		*end;
	size_t		cap;
}				t_string;

int				t_string_by_buf(t_string *const tstr, char const *buf, size_t sz);
int				t_string_by_cstr(t_string *const tstr, char *str); 
t_string		*new_string_by_buf(char const *buf, size_t sz);
t_string		*new_string_by_cstr(char *str);
void			rls_string(t_string *const tstr);
void			destroy_string(t_string *const tstr);
#endif
