NAME = Animals
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
CXX = c++
HDR = Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp
OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(HDR)
	@$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)
clean:
	@rm -f *.o
fclean: clean
	@rm -f $(NAME)
re: fclean all

run: all
	@./$(NAME)

.PHONY: all clean fclean re run
