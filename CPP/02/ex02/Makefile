NAME = Overloading_Madeness
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Fixed.cpp
CXX = c++
HDR = Fixed.hpp
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
