#ifndef PF_CONV_C
# define PF_CONV_C
# define MY_CHAR_CONV 'c'
# define MY_DEF_CONV {.normalize=normalize_c,.get_field=get_field_c,.decorate=decorate_c,.end=end_c}
# ifndef PF_CHAR_CONV
#  define PF_CHAR_CONV MY_CHAR_CONV
#  define PF_DEF_CONV MY_DEF_CONV
# else
#  define LOC_CHAR_CONV PF_CHAR_CONV
#  define LOC_DEF_CONV PF_DEF_CONV
#  undef PF_CHAR_CONV
#  undef PF_DEF_CONV
#  define PF_CHAR_CONV LOC_CHAR_CONV,MY_CHAR_CONV
#  define PF_DEF_CONV LOC_DEF_CONV,MY_DEF_CONV
#  undef LOC_CHAR_CONV
#  undef LOC_DEF_CONV
# endif
# undef MY_CHAR_CONV
# undef MY_DEF_CONV
# include "conv.h"
# include "bank.h"

t_normalizer	normalizer_c = ;
t_get_field		get_field_c = ;
t_decorate		decorate_c = ;
t_end			end_c = ;

#endif 
