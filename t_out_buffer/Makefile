NAME = t_out_buffer.o
CFLAG = -Wall -Wextra -Werror

.PHONY: all
all: $(NAME)

$(NAME): t_out_buffer.c t_out_buffer.h.gch
	gcc $(CFLAG) -c $<

t_out_buffer.h.gch: t_out_buffer.h
	gcc $(CFLAG) $<

.PHONY: clean
clean:
	rm -f t_out_buffer.h.gch

.PHONY: fclean
fclean: clean
	rm -f t_out_buffer.o
	
