NAME = PmergeMe
CPPFLAGS = -g -Wall -Wextra -Werror -std=c++98
SRC = main.cpp PmergeMe.cpp
CXX = c++
HDR = PmergeMe.hpp
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
test:
	@./$(NAME) 5 2 3 1 4 7 6
t5:
	@$(eval ARG = $(shell seq 1 20000 | shuf -n 5))
	@./PmergeMe $(ARG)

t1k:
	@$(eval ARG = $(shell seq 1 20000 | shuf -n 1000))
	@./PmergeMe $(ARG)
.PHONY: all clean fclean re run
