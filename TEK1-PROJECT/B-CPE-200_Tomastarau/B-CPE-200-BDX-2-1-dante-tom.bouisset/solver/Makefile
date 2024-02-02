##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME	=	solver

SRC = 	src/solver.c 	\
		src/file_to_str.c 	\
		src/my_str_array.c 	\
		src/error_maze.c 	\
		src/a_star.c 		\
		src/maze_length.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -I ../include/

all: $(NAME)

make_libs:
	make -C ../../lib/my

$(NAME):  $(make_lib) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re make_libs
