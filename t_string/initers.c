#include "t_string.h"
#include "libft.h"

int			t_string_by_buf(t_string *const tstr, char const *buf, size_t sz)
{
	if (!tstr)
		return (T_STRING_INIT_ERROR);
	ft_bzero(tstr, sizeof(t_string));
	tstr->cap = T_STRING_INIT_SIZE;
	while (tstr->cap < sz + 1)
		tstr->cap *= 2;
	if ((tstr->start = malloc(sizeof(char) * tstr->cap)))
	{
		tstr->end = tstr->start - 1;
		while (tstr->end - tstr->start < sz)
			*++tstr->end = *cur++;
		return (T_STRING_INIT_OK); 
	}
	return (T_STRING_INIT_ERROR);
}

int			t_string_by_cstr(t_string *const tstr, char const *str)
{
	return (t_string_by_buf(tstr, str, ft_strlen(str)));
}

t_string	*new_string_by_buf(char const *buf, size_t sz)
{
	t_string *new;

	if ((new = malloc(sizeof(t_string))))
	{
		if (t_string_by_buf(new, buf, sz) == T_STRING_INIT_ERROR)
			free(new);
	}
	return (new);
}

t_string	*new_string_by_cstr(char *str)
{
	return (new_string_by_buf(str, ft_strlen(str)));
}

