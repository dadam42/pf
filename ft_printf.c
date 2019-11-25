#include "ft_printf.h"
#include "t_out_buffer.h"
#include <stdarg.h>

int ft_vadprintf(int fd, char const* str, va_list pfargs)
{
	t_out_buffer	buf;
	char const*		strmem;

	if (t_out_buffer_init(&buf, fd) == T_OUT_BUFFER_INIT_ERROR)
		return (FT_PRINTF_RET_ERROR);
	while (1)
	{
		strmem = str;
		while (*str && *str != '%')
			str++;
		if (!*str)
			return (t_out_buffer_flush(&buf));
		t_out_bufferize(&buf, strmem, str);
		if (ft_pf_parse(&str, &buf, &pfargs) == FT_PF_PARSE_ERROR)
			return (FT_PRINTF_ERROR);
	}
}

int ft_printf(char const *str, ...)
{
	va_list	pfargs;
	int 	ret;

	va_start(pfargs, str);
	ret = ft_vadprintf(1, str, pfargs);
	va_end(pfargs);
	return (ret);
}