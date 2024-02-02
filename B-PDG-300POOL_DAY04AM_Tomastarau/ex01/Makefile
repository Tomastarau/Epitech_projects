##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile
##

NAME	=	a.out

SRC = mul_div.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -std=gnu17 -I include

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f

fclean : clean
	rm -f $(NAME)
	rm -f unit_tests
	rm -f *.gcda
	rm -f *.gcno
	rm -f *~

re: fclean all

.PHONY: clean fclean all re NAME
