##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME	=	mysh

SRC = 	src/main.c			\
		src/mysh.c		\
		src/handling.c	\
		src/execution.c	\
		src/env.c		\
		src/set_env_no_value.c 	\
		src/full_path.c 		\
		src/setenv_functions.c

OBJ = $(SRC:.c=.o)

LDFLAGS = -L ./lib/ -lmy

CFLAGS = -Wall -Wextra -I include

all: $(NAME)

make_libs:
	make -C ./lib/my

$(NAME):  $(make_lib) $(OBJ)
	make -C ./lib/my
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	make clean -C ./lib/my
	rm -f $(OBJ)

fclean : clean
	make fclean -C ./lib/my
	rm -f $(NAME)
	rm -f vgcore~

re: fclean all

.PHONY: clean fclean all re make_libs NAME
