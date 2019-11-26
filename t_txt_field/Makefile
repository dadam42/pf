NAME = t_txt_field.o
CFLAGS = -Wall -Wextra

.PHONY: all
all: $(NAME)

$(NAME): t_txt_field.c t_txt_field.h.gch
	gcc $(CFLAGS) -c $<

t_txt_field.h.gch: t_txt_field.h
	gcc $(CFLAGS) $<

.PHONY: clean
clean:
	rm -f t_txt_field.h.gch

.PHONY: fclean
fclean: clean
	rm -f t_txt_field.o
