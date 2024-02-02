##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME	=	make

all:		$(NAME)

make:
		$(MAKE) -C	generator/
		$(MAKE)	-C	solver/

clean:
		rm -f $(OBJ)
		$(MAKE) clean -C generator/
		$(MAKE) clean -C solver/

fclean: 	clean
		rm -f $(NAME)
		$(MAKE) fclean -C generator/
		$(MAKE) fclean -C solver/

run_tests:

re:		fclean all
		$(MAKE) re -C generator/
		$(MAKE) re -C solver/
