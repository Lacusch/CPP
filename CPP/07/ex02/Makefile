NAME = Array
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp
CXX = c++
HDR = Array.hpp
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
1:
	./$(NAME) 1
2:
	./$(NAME) 2
3:
	./$(NAME) 3
4:
	./$(NAME) 4
5:
	./$(NAME) 5
.PHONY: all clean fclean re run
