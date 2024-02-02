##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC		=	./my_printf/my_printf.c		\
			./my_printf/find_next_flag.c	\
			./src/swap_elem.c 			\
			./src/bubble_swap.c		\
			./my_printf/printf_p.c \
			./my_printf/printf_c.c	\
			./my_printf/printf_d.c	\
			./my_printf/printf_i.c	\
			./my_printf/printf_o.c 	\
			./my_printf/printf_pourcentage.c 	\
			./my_printf/printf_s.c 	\
			./my_printf/printf_u.c 	\
			./my_printf/printf_x_up.c	\
			./my_printf/printf_x.c 	\
			./my_printf/struct.c	\
			lib/my/my_putchar.c	\
			lib/my/my_put_nbr.c	\
			lib/my/my_putstr.c	\
			lib/my/my_putnbr_base.c	\
			lib/my/my_strlen.c

OBJ		=	$(SRC:.c=.o)

NAME		=	libmy.a

CPPFLAGS	=	-I ./include

all:	$(NAME)

$(NAME): $(OBJ)
		ar rc  $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(NAME)
	rm -f *.gcda
	rm -f *.gcno

re:	fclean all

unit_tests: clean
	gcc -o unit_tests $(SRC) test_swap/test.c -I./include \
	--coverage -lcriterion
tests_run: unit_tests
		./unit_tests

run_tests: unit_tests
		./unit_tests

.PHONY: all clean fclean re unit_tests tests_run run_tests
