#ifndef PF_CONV_C
# define PF_CONV_C
# include <stddef.h>
# define C_CHAR 'c'
# define C_BHV {.format_rule=c_rule,.init=c_init,.exec=c_exec}
# include "conv.h"
t_format_rule const c_rule=NULL;
t_init_conv const c_init=NULL;
t_exec_conv const c_exec=NULL;
#endif 
