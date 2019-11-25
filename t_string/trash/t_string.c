#include "t_string.h"

int			*init_string_by_buf(t_string *const tstr, char const*buf, size_t sz)
{
	if (!tstr)
		return (T_STRING_INIT_ERROR);
	ft_memzero(tstr, sizeof(t_string));
	tstr->cap = T_STRING_INIT_SIZE;
	while (tstr->cap < sz + 1)
		tstr->cap *= 2;
	if (tstr->start = malloc(sizeof(char) * tstr->cap))
	{
		ft_memcpy(tstr->start, buf, sz);
		str->end = str->start + sz;
		return (T_STRING_INIT_OK); 
	}
	return (T_STRING_INIT_ERROR);
}

int			*init_string_by_str(t_string *const tstr, char const *str)
{
	return (init_string_by_buf(tstr, str, ft_strlen(str)));
}

t_string	*new_string_by_buf(char *buf, size_t sz)
{
	t_string *new;

	if (new = malloc(sizeof(t_string)))
	{
		if (init_string_by_buf(new, buf, sz) == T_STRING_INIT_ERROR)
			free(new);
	}
	return (new);

}

t_string	*new_string_by_str(char *str)
{
	return (new_string_by_buf(str, ft_strlen(str)));
}

void		uninit_string(t_string *const tstr)
{
	free(tstr->start);
}

void		destroy_string(t_string *const tstr)
{
	if (tstr)
	{
		free(tstr->start);
		free(tstr);
	}
}
