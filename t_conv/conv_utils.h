#ifndef CONV_UTIL_H
# define CONV_UTIL_H
typedef struct s_conv	t_conv;
typedef void			(*t_format_rule)(t_pf_format *fmt);
typedef	int				(*t_init_conv)(t_conv *conv, va_list *pfargs);
typedef int				(*t_exec_conv)(t_conv *conv, t_out_buffer *buf);
#endif
