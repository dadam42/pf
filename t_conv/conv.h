#ifndef T_CONV_H
# define T_CONV_H
# include "t_pf_format.h"
# include "t_txt_field.h"
# include "t_out_buffer.h"
# include <stdarg.h>
# define CONV_ACTION_OK 1
# define CONV_ACTION_ERROR 0
# define CONV_INIT_OK 1
# define CONV_INIT_ERROR 0

typedef struct s_conv	t_conv;
typedef void			(*t_normalize)(t_pf_format *fmt);
typedef int				(*t_exec)();
typedef t_txt_field		(*t_get_field)(t_pf_format *fmt,
									va_list *pfargs, t_com *com); 
typedef void			(*t_decorate)(t_pf_format *fmt,
									t_txt_field *field, t_com *com);
typedef void			(*t_end)(t_txt_field *field, t_com *com);
struct					s_conv
{
	t_normalize		normalize;
	void			*com;
}

int					conv_init(t_conv *conv, t_pf_format *fmt,
								va_list *pfargs);
#endif
