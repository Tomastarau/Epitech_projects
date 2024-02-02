##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile
##

NAME = a.out

CXX = g++

CXXFLAGS = -std=c++20 -Wall -Wextra -Werror

SRC = 	Federation.cpp	\
		WarpSystem.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
