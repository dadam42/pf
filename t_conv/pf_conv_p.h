#ifndef PF_CONV_P
# define PF_CONV_P
# include <stddef.h>
# define P_CHAR 'p'
# define P_BHV {.format_rule=p_rule,.init=p_init,.exec=p_exec}
# include "conv.h"
t_format_rule const p_rule=NULL;
t_init_conv const p_init=NULL;
t_exec_conv const p_exec=NULL;
#endif 
