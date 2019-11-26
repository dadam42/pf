#ifndef PF_FORMAT_UTIL_H
# define PF_FORMAT_UTIL_H
# include "t_pf_format.h"
# include "t_txt_field"
# include <stdarg.h>

typedef void	(*t_normalize)(t_pf_format *fmt);
typedef t_txt_field	(*t_get_field)(t_pf_format *fmt, va_list *pfargs); 
typedef void		(*t_decorate)(t_pf_format *fmt, t_txt_field *field);
typedef void		(*t_end)(t_txt_field *field);
typedef struct		s_exec_datas
{
	t_normalizer	normalize;
	t_get_field		get_field;
	t_decorate		decorate;
	t_end			end;
}					t_exec_datas;
#endif
