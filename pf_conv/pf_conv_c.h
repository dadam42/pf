#ifndef PF_CONV_C
# ifndef PF_CONV_C
# ifndef PF_CHAR_CONV
#  define PF_CHAR_CONV 'c'
# else
#  define LOC_CHAR_CONV PF_CHAR_CONV
#  undef PF_CHAR_CONV
#  define PF_CHAR_CONV LOC_CHAR_CONV , 'c'
#  undef LOC_CHAR_CONV
# endif

#endif 
