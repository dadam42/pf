#include "util.h"
#include "t_string.h"
#include "t_str_iterator.h"

char *fwd_step(t_str_iterator *it, int s)
{
	char *ret;

	if (s <= 0)
	{
		if (it->ref < it->str->start)
			return (NULL);
		ret = it->ref;
		it->ref = (it->str->start <= it->ref + s ? s + it->ref : it->str->start - 1);
		return (ret);
	}
	return (bwd_step(it, -s));
}

char *bwd_step(t_str_iterator *it, int s)
{
	char *ret;

	if (s <= 0)
	{
		if (it->ref > it->str->end)
			return (NULL);
		ret = it->ref;
		it->ref = ( it->str->end >= it->ref - s ? it->ref - s : it->str->end + 1);
		return (ret);
	}
	return (fwd_step(it, -s));
}

char *fwd_next(t_str_iterator *it)
{
	if (it->ref > it->str->end)
		return (NULL);
	return (it->ref++);
}

char *fwd_prev(t_str_iterator *it)
{
	if (it->ref < it->str->start)
		return (NULL);
	return (it->ref--);
}

void fwd_init(t_str_iterator *it)
{
	it->ref = it->str->start;
}

void bwd_init(t_str_iterator *it)
{
	it->ref = it->str->end;
}
