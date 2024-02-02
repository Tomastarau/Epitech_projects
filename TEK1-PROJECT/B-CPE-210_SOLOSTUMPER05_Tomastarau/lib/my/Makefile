##
## EPITECH PROJECT, 2022
## make file
## File description:
## task01
##

NAME 	=	libmy.a	\

SRC	=	./src/my_str_to_word_array_2.c

OBJ	=	$(SRC:.c=.o)

FLAGS = -Wall -Wextra

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ../$(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all

.PHONY: clean fclean all re
