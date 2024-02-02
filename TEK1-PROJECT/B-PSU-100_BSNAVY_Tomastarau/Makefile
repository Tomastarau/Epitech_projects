##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME	=	bs_navy

SRC = src/exo1.c

OBJ = $(SRC:.c=.o)

LDFLAGS = -L ./lib/ -lmy

CFLAGS = -Wall -Wextra -I include

all: $(NAME)

make_libs:
	make -C ./lib/my

$(NAME):  $(make_lib) $(OBJ)
	gcc -o process_info $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re make_libs
