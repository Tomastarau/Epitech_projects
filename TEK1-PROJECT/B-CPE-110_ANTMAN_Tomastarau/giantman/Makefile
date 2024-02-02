##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME	=	giantman

SRC = 	src/texte_decompression/my_giantman.c			\
		src/texte_decompression/algorithm_functions.c	\
		src/texte_decompression/array_management.c 		\
		src/texte_decompression/print_functions.c 		\
		src/image_decompression/image_decompression.c	\
		src/image_decompression/file_to_str.c

OBJ = $(SRC:.c=.o)

LDFLAGS = -L ../lib/ -lmy

CFLAGS = -Wall -Wextra -I include

all: $(NAME)

make_libs:
	make -C ../lib/my

$(NAME):  $(make_lib) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re make_libs
