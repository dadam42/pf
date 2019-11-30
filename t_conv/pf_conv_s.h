#ifndef PF_CONV_S
# define PF_CONV_S
# include <stddef.h>
# include "conv.h"
# define S_CHAR 's'
# define S_BHV {.format_rule=s_rule,.init=s_init,.exec=s_exec}
t_format_rule const s_rule=NULL;
t_init_conv const s_init=NULL;
t_exec_conv const s_exec=NULL;
#endif 
