##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME	=	generator

SRC = 	src/generator.c				\
		src/fill_map.c				\
		src/main.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -I ../include/

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re make_libs
