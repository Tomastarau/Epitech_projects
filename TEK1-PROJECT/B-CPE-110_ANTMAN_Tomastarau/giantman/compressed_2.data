##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME	=	antman

SRC = 	my_antman.c				\
		main.c    				\
		src/texte_compression/algorithm_functions.c		\
		src/texte_compression/array_management.c 		\
		src/texte_compression/print_functions.c			\
		src/image_compression/image_compression.c 		\
		src/image_compression/file_to_str.c

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
