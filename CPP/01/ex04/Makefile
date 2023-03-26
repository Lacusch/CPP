NAME = mysed
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp
CXX = c++

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)
clean:
	@rm -f *.o
	@rm -f *.replace
fclean: clean
	@rm -f $(NAME)
t1: $(NAME)
	@echo "Using the Makefile as a base and replacing NAME with test"
	@./$(NAME) Makefile NAME test
t2: $(NAME)
	@echo "Using the Makefile as a base and replacing SRC with test"
	@./$(NAME) Makefile SRC test
t3: $(NAME)
	@echo "Using the Makefile as a base and replacing t with test"
	@./$(NAME) Makefile t test
re: clean fclean all tests t1 t2 t3
