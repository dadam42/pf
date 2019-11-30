#ifndef PF_CONV_U
# define PF_CONV_U
# include <stddef.h>
# define U_CHAR 'u'
# define U_BHV {.format_rule=u_rule,.init=u_init,.exec=u_exec}
# include "conv.h"
t_format_rule const u_rule=NULL;
t_init_conv const u_init=NULL;
t_exec_conv const u_exec=NULL;
#endif 
