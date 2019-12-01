#ifndef PF_PARSER_H
# define PF_PARSER_H
# define PF_PARSE_ERROR -1
# define PF_PARSE_OK 1
# include "t_out_buffer.h"
# include <stdarg.h>

int	pf_parse_exec(char const **str, t_out_buffer *buf, va_list *pfargs);
#endif
