#ifndef PF_CONV_XL
# define PF_CONV_XL
# include <stddef.h>
# define XL_CHAR 'xl'
# define XL_BHV {.format_rule=xl_rule,.init=xl_init,.exec=xl_exec}
# include "conv.h"
t_format_rule const xl_rule=NULL;
t_init_conv const xl_init=NULL;
t_exec_conv const xl_exec=NULL;
#endif 
