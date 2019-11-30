#ifndef PF_CONV_D
# define PF_CONV_D
# include <stddef.h>
# define D_CHAR 'd'
# define D_BHV {.format_rule=d_rule,.init=d_init,.exec=d_exec}
# include "conv.h"
t_format_rule const d_rule=NULL;
t_init_conv const d_init=NULL;
t_exec_conv const d_exec=NULL;
#endif 
