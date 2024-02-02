##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME	=	navy

SRC = 	src/main.c 	\
		src/h_option.c 	\
		src/connection.c 	\
		src/print_sigusr.c 	\
		src/my_navy.c		\
		src/map_handling.c	\
		src/print_function.c	\
		src/error_handling.c

OBJ = $(SRC:.c=.o)

LDFLAGS = -L ./lib/ -lmy

CFLAGS = -Wall -Wextra -I include

all: $(NAME)

make_libs:
	make -C ./lib/my

$(NAME):  $(make_lib) $(OBJ)
	make -C ./lib/my
	gcc -o navy $(OBJ) $(LDFLAGS)

clean:
	make clean -C ./lib/my
	rm -f $(OBJ)

fclean : clean
	make fclean -C ./lib/my
	rm -f $(NAME)
	rm -f vgcore~

re: fclean all

.PHONY: clean fclean all re make_libs
