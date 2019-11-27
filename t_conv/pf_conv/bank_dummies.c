#include "conv.h"
#include "t_pf_format.h"
#include "t_txt_field.h"
#include <stdarg.h>

void dummy_normalizer(t_pf_format *fmt)
{
	void(fmt);
}

t_get_field *dummy_get_field(t_pf_format *fmt, va_list *pfarg, t_com *com)
{
	void(fmt);
	void(pfargs);
	void(com);
	return (NULL);
}

void dummy_decorator(t_pf_format *fmt, t_txt_field *field, t_com *com)
{
	void(fmt);
	void(field);
	void(com);
}

void dummy_end(t_txt_field *field, t_com *com)
{
	void(field);
	void(field);
}
