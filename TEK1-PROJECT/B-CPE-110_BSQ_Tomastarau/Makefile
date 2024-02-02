##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC		=	./src/folder_into_1d_array.c 			\
			./main.c 							\
			./src/create_map.c							\
			./my_printf/my_printf.c					\
			./my_printf/find_next_flag.c			\
			./my_printf/printf_p.c 					\
			./src/my_get_nbr.c 						\
			./src/nb_rows.c 						\
			./src/nb_column.c 						\
			./my_printf/printf_c.c					\
			./my_printf/printf_d.c					\
			./my_printf/printf_i.c					\
			./my_printf/printf_o.c 					\
			./my_printf/printf_pourcentage.c 		\
			./my_printf/printf_s.c 					\
			./my_printf/printf_u.c 					\
			./my_printf/printf_x_up.c				\
			./my_printf/printf_x.c 					\
			./my_printf/struct.c					\
			lib/my/my_str_to_word_array.c			\
			lib/my/my_putchar.c						\
			lib/my/my_put_nbr.c						\
			lib/my/my_putnbr_base.c						\
			lib/my/my_putstr.c						\
			lib/my/my_strlen.c						\
			lib/my/my_strcmp.c						\
			lib/my/my_strcpy.c

OBJ		=	$(SRC:.c=.o)

NAME		=	libmy.a

CPPFLAGS	=	-I ./include

all:	$(NAME)

$(NAME): $(OBJ)
		ar rc  $(NAME) $(OBJ)
		gcc -o ./bsq src/*.c libmy.a -g -I ./include

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(NAME)
	rm -f bsq
	rm -f *.gcda
	rm -f *.gcno

re:	fclean all

unit_tests: clean
	gcc -o unit_tests $(SRC) test_myprintf/tests.c -I./include \
	--coverage -lcriterion
tests_run: unit_tests
		./unit_tests

run_tests: unit_tests
		./unit_tests

.PHONY: all clean fclean re unit_tests tests_run run_tests
