#ifndef TEST_H
# define TEST_H

# ifdef D42_TEST_C
#  define D42_FCNT 9
#  define D42_WCNT 7
#  define D42_PCNT 6
#  define D42_WARGS {"", "1", "2", "17", "-1", "-2", "-17"}
#  define D42_PARGS {"", ".1", ".2", ".8", ".", ".0"}
#  define D42_FARGS  {"", "0", "-", "0-", "-0", "0-0", "00-", "-0-", "-00"}
#  define D42_WACNT 6
#  define D42_WAARGS {-1, -2, 0, 1, 2, 17 }
#  define D42_PACNT 6
#  define D42_PAARGS {-3, -1, 0, 1, 2, 8}
#  define D42_ACNT 1
#  define D42_ARGS {'y'}
#  define D42_ATYPE char
#  define D42_CONV "c"
# endif

# ifdef D42_TEST_S
#  define D42_ACNT 3
#  define D42_ARGS {"0123456789abcdefghijklmno", "", 0}
#  define D42_ATYPE char*
#  define D42_CONV "s"
# endif

# ifdef D42_TEST_D
#  define D42_ACNT 3
#  define D42_ARGS {42, 0, -42}
#  define D42_ATYPE int
#  define D42_CONV "d"
# endif

# ifdef D42_TEST_U
#  define D42_ACNT 3
#  define D42_ARGS {42, 0, 123456789}
#  define D42_ATYPE unsigned int
#  define D42_CONV "u"
# endif

# ifdef D42_TEST_XU
#  define D42_ACNT 3
#  define D42_ARGS {42, 0, 123456789}
#  define D42_ATYPE unsigned int
#  define D42_CONV "X"
# endif

# ifdef D42_TEST_XL
#  define D42_ACNT 3
#  define D42_ARGS {42, 0, 123456789}
#  define D42_ATYPE unsigned int
#  define D42_CONV "x"
# endif

# ifdef D42_TEST_P
#  define D42_ACNT 3
#  define D42_ARGS {NULL, 1, 123456789}
#  define D42_ATYPE int
#  define D42_CONV "p"
# endif

# ifdef D42_TEST_PE
#  define D42_ACNT 1
#  define D42_ARGS {42}
#  define D42_ATYPE int
#  define D42_CONV "%"
# endif

# ifndef D42_FCNT
#  define D42_FCNT 9
# endif

# ifndef D42_WCNT
#  define D42_WCNT 7
# endif

# ifndef D42_PCNT
#  define D42_PCNT 6
# endif

# ifndef D42_WARGS
#  define D42_WARGS {"", "1", "2", "17", "-1", "-2", "-17"}
# endif

# ifndef D42_PARGS
#  define D42_PARGS {"", ".1", ".2", ".8", ".", ".0"}
# endif

# ifndef D42_FARGS
#  define D42_FARGS  {"", "0", "-", "0-", "-0", "0-0", "00-", "-0-", "-00"}
# endif

# ifndef D42_WACNT
#  define D42_WACNT 6
# endif

# ifndef D42_WAARGS
#  define D42_WAARGS {-1, -2, 0, 1, 2, 17 }
# endif

# ifndef D42_PACNT
#  define D42_PACNT 6
# endif

# ifndef D42_PAARGS
#  define D42_PAARGS {-3, -1, 0, 1, 2, 8}
# endif

#endif
