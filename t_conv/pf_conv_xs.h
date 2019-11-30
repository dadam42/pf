#ifndef PF_CONV_XS
# define PF_CONV_XS
# include <stddef.h>
# define XS_CHAR 'xs'
# define XS_BHV {.format_rule=xs_rule,.init=xs_init,.exec=xs_exec}
# include "conv.h"
t_format_rule const xs_rule=NULL;
t_init_conv const xs_init=NULL;
t_exec_conv const xs_exec=NULL;
#endif 
