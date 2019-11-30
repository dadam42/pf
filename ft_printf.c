#include "ft_printf.h"
#include "t_out_buffer.h"
#include "pf_parser.h"
#include <stdarg.h>

int ft_vadprintf(int fd, char const* str, va_list *pfargs)
{
	t_out_buffer	buf;
	char const*		strmem;

	t_out_buffer_init(&buf, fd);
	while (1)
	{
		strmem = str;
		while (*str && *str != '%')
			str++;
		if (!*str)
			return (t_out_buffer_flush(&buf));
		t_out_buffer_ize(&buf, strmem, str);
		str++;
		if (pf_parse_exec(&str, &buf, pfargs) == PF_PARSE_ERROR)
			return (FT_PRINTF_RET_ERROR);
	}
}

int ft_printf(char const *str, ...)
{
	va_list	pfargs;
	int 	ret;

	va_start(pfargs, str);
	ret = ft_vadprintf(1, str, &pfargs);
	va_end(pfargs);
	return (ret);
}
