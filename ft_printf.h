#ifndef FT_PRINTF_H
# define FT_PRTINF_H
# define FT_PRINTF_RET_ERROR -1
# include <stdarg.h>

int ft_vadprintf(int fd, char const* str, va_list);
int	ft_printf(char const * str, ...);
#endif
