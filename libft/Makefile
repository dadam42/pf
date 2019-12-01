COMP = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = libft.a
SRCS = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp ft_strlen \
		ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_strchr \
		ft_strrchr ft_strncmp ft_strlcpy ft_strlcat ft_strnstr ft_atoi ft_otg_atoi ft_calloc ft_strdup \
		ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_ltoa ft_ptrtoa ft_itoa_base ft_uitoa_base ft_strmapi ft_putchar_fd \
		ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_ischarinset ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast \
		ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap 
SRCSDIR = srcs/ 
INCLUDEDIR = includes/

all : ${NAME}

$(NAME) : ${SRCS:%=srcs/%.o} 
	ar rc ${NAME} ${SRCS:%=srcs/%.o}
	ranlib ${NAME}

%.o : %.c
	${COMP} $(DFLAG) ${CFLAGS} -I${INCLUDEDIR}  -c $< -o $@

clean :
	rm -f ${SRCS:%=srcs/%.o}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
