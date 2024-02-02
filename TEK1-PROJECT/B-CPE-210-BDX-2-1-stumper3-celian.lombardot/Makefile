##
## EPITECH PROJECT, 2023
## stumper
## File description:
## Makefile
##

SOURCE_DIR	=	src/

SRC	=	main.c	\
		check_args.c	\
		get_map.c	\
		if_unstable.c	\
		drop_sand.c	\
		locate_unstability.c	\
		convert_tab.c	\
		sandpile.c

OBJ	=	$(addprefix $(SOURCE_DIR), $(SRC:.c=.o))

TO_TEST	=	tests/test_check_args.c	\
		tests/test_get_map.c	\
		tests/test_sandpile.c	\
		src/get_map.c	\
		src/if_unstable.c	\
		src/drop_sand.c	\
		src/locate_unstability.c	\
		src/convert_tab.c	\
		src/sandpile.c	\
		src/check_args.c

CPPFLAGS	=	-I./include

CFLAGS	=	-W -Wall -Wextra

NAME	=	sandpile

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LFLAGS)

tests_run: unit_tests
	./unit_tests

unit_tests:
	gcc -o unit_tests $(TO_TEST) -I./include	\
	--coverage -lcriterion

clean:
	rm -f $(OBJ)
	find . -name "*~" -delete
	find . -name '#'*'#' -delete

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all tests_run unit_tests tests_run clean fclean re
