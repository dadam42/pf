#ifndef T_PF_FORMAT_H
# define T_PF_FORMAT_H
/*
** Flags' constants, add constants to handle more flags.
** Don't forget to increase t_flags if needed.
*/
# define FMT_ZERO		1
# define FMT_MINUS		2
# define FMT_WIDTH		4
# define FMT_PREC		8
/*
** Possible return values for pf_format_exec function.
*/
# define FMT_EXEC_OK	1
# define FMT_EXEC_ERROR	2
# include <stdarg.h>
# include "t_out_buffer.h"
# include "general_bank.h"

typedef unsigned char	t_flags;
typedef struct			s_pf_format
{
	t_flags				flags;
	int					width;
	int					prec;
	char				conv_char;
}						t_pf_format;

void					pf_format_normalize(t_pf_format *fmt)
						= general_normalization;
#endif
