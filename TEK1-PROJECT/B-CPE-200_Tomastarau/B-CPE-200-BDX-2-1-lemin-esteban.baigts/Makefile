##
## EPITECH PROJECT, 2023
## lemin
## File description:
## Makefile
##

MAIN 	=		main.c

LIB 	= 		lib/array_utils.c 					\
				lib/list_utils.c 						\
				lib/print_output.c 					\
				lib/str_chr.c 						\
				lib/str_cmp.c 						\
				lib/str_cpy.c 						\
				lib/str_dup.c 						\
				lib/str_len.c 						\
				lib/str_to_num.c 						\
				lib/str_to_word_arr.c 

SRC		=		src/room.c 									\
				src/parser.c 								\
				src/link.c 									\
				src/anthill.c 								\
				src/anthill_parse.c 						\
				src/anthill_parse_room.c 					\
				src/anthill_parse_link.c 					\

CFLAGS += -Werror

OBJ		=		$(SRC:.c=.o) $(MAIN:.c=.o) $(LIB:.c=.o)

NAME	= 		lem_in

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
