##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME	=	clean_str

SRC = src/clean_str.c

OBJ = $(SRC:.c=.o)

LDFLAGS = -L lib/ -lmy

CFLAGS = -Wall -Wextra -I include

all: $(NAME)

make_libs:
	make -C lib/my

$(NAME):  $(make_lib) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	rm -f *.gcda
	rm -f *.gcno

re: fclean all

unit_tests : clean
	gcc -o unit_tests $(SRC) test_stumper/test.c \
	-I./include/ --coverage -lcriterion $(LDFLAGS) -g

tests_run : unit_tests
		./unit_tests

run_tests : unit_tests
		./unit_tests

.PHONY: clean fclean all re make_libs
