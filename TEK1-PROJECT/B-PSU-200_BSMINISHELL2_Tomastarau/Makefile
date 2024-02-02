##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME	=	mysh

SRC = 	src/main.c			\
		src/others/mysh.c		\
		src/others/handling.c	\
		src/others/execution.c	\
		src/env/env.c		\
		src/env/set_env_no_value.c 	\
		src/parsing/full_path.c 		\
		src/env/setenv_functions.c	\
		src/others/chained_list.c		\
		src/parsing/pipe_exec_fonction.c 	\
		src/others/chained_list_to_word_array.c	\
		src/parsing/command_array_handling.c 	\
		src/parsing/multiple_command_verif.c 	\
		src/parsing/str_commands_to_array.c

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
