#ifndef T_CONV_H
# define T_CONV_H
# include "t_pf_format.h"
# include "t_txt_field.h"
# include "t_out_buffer.h"
# include <stdarg.h>
# include <stddef.h>
# include "conv_utils.h"
# include "pf_conv_s.h"
# include "pf_conv_c.h"
# include "t_pf_format.h"
# define CONV_EXEC_OK 1
# define CONV_EXEC_ERROR 0
# define CONV_INIT_OK 1
# define CONV_INIT_ERROR 0
# define PF_CHARS S_CHAR, C_CHAR
# define PF_BHVS S_BHV
# define PF_CONV_STRING {PF_CHARS,0}
# define PF_CONV_BEHAVIOURS {PF_BHVS,C_BHV}
# define PF_DEFAULT_BEHAVIOUR {.format_rule=NULL,.init=NULL,.exec=NULL}
# define PF_CONV_COUNT 2

struct					s_conv
{
	t_format_rule	format_rule;
	t_init_conv		init;
	t_exec_conv		exec;
	void			*com;
	t_pf_format		*fmt;
};

int					conv_init(t_conv *conv, t_pf_format *fmt,
								va_list *pfargs);
#endif
