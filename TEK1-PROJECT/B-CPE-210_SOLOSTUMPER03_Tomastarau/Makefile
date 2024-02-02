##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME	=	fazzbizz

SRC = src/fazzbizz.c	\
	src/utils.c

MAIN = src/main.c

OBJ = $(SRC:.c=.o)

OBJ_MAIN = $(MAIN:.c=.o)

LDFLAGS = -L lib/ -lmy

CFLAGS = -Wall -Wextra -I include

all: $(NAME) $(make_libs)

make_libs:
	make -C lib/my

$(NAME): $(make_libs) $(OBJ) $(OBJ_MAIN)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(OBJ_MAIN) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean : clean
	make fclean -C lib/my
	rm -f $(NAME)
	rm -f unit_tests
	rm -f *.gcda
	rm -f *.gcno
	rm -f *~

re: fclean all

unit_tests : clean
	gcc -o unit_tests $(SRC) test_stumper/test.c \
	-I./include/ --coverage -lcriterion -g

tests_run : unit_tests
		./unit_tests

run_tests : unit_tests
		./unit_tests

.PHONY: clean fclean all re make_libs NAME unit_tests tests_run run_tests
