##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME	=	arg_joiner

SRC = src/arg_joiner.c	\
	src/utils.c

MAIN = src/main.c

OBJ = $(SRC:.c=.o)

OBJ_MAIN = $(MAIN:.c=.o)

CFLAGS = -Wall -Wextra -I include

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN)
	gcc -o $(NAME) $(OBJ) $(OBJ_MAIN)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_MAIN)

fclean : clean
	rm -f $(NAME)
	rm -f unit_tests
	rm -f *.gcda
	rm -f *.gcno
	rm -f *~

re: fclean all

.PHONY: clean fclean all re NAME
