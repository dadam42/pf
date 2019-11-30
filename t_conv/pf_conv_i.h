#ifndef PF_CONV_I
# define PF_CONV_I
# include <stddef.h>
# define I_CHAR 'i'
# define I_BHV {.format_rule=i_rule,.init=i_init,.exec=i_exec}
# include "conv.h"
t_format_rule const i_rule=NULL;
t_init_conv const i_init=NULL;
t_exec_conv const i_exec=NULL;
#endif 
