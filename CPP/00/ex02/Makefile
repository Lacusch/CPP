NAME = My_Awesome_Banking_System
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = tests.cpp Account.cpp
CXX = c++
HDR = Account.hpp

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

test: $(NAME)
	@mkdir -p logs
	@./$(NAME) | cut -c 19- > logs/my.log
	@ cut -c 19- 19920104_091532.log > logs/original.log
$(NAME): $(OBJ) $(HDR)
	@$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)
clean:
	@rm -f *.o
fclean: clean
	@rm -f $(NAME)
	@rm -rf logs
re: fclean all

run: all
	@./$(NAME) >> new.log
.PHONY: all test clean fclean re run
