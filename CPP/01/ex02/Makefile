NAME = BRAIN
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp
CXX = c++

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)
clean:
	@rm -f *.o
fclean: clean
	@rm -f $(NAME)
	@rm -rf logs
re: fclean all

run: all
	@./$(NAME)

.PHONY: all clean fclean re run
