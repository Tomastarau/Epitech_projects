##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile
##


SRC		=	ex00.c	\
			ex01.c	\
			ex02.c 	\
			ex03.c 	\
			ex04.c 	\
			ex05.c 	\
			ex06.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -std=gnu17 -I include

all: libstring.a

libstring.a: $(OBJ)
	ar rc $@ $^

clean:
	rm -f a.out
	rm -f $(OBJ)
	rm -f *~

fclean: clean
	rm -f libstring.a
	rm -f unit_tests
	rm -f *.gcda
	rm -f *.gcno

re: fclean all

.PHONY: clean fclean all re
