NAME = megaphone
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = megaphone.cpp
CXX = c++


OBJ = $(SRC:%.cpp=%.o)
all: $(NAME)

$(NAME) : $(OBJ)
	@$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f *.o
fclean: clean
	@rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
