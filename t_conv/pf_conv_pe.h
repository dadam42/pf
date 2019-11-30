#ifndef PF_CONV_PE
# define PF_CONV_PE
# include <stddef.h>
# define PE_CHAR 'pe'
# define PE_BHV {.format_rule=pe_rule,.init=pe_init,.exec=pe_exec}
# include "conv.h"
t_format_rule const pe_rule=NULL;
t_init_conv const pe_init=NULL;
t_exec_conv const pe_exec=NULL;
#endif 
