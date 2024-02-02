##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME = DoOp

SRC = DoOp.hs

HC = ghc

HCFLAGS = -Wall -Wextra

all: $(NAME)

$(NAME): $(SRC)
	$(HC) $(HCFLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME) *.hi *.o *~

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
