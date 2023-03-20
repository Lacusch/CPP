NAME = My_Awesome_PhoneBook
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp PhoneBook.cpp Contact.cpp
CXX = c++
HDR = Contact.hpp PhoneBook.hpp

OBJ = $(SRC:%.cpp=%.o)
all: $(NAME)

$(NAME) : $(OBJ) $(HDR)
	@$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)
clean:
	@rm -f *.o
fclean: clean
	@rm -f $(NAME)
re: fclean all

run: all
	@./$(NAME)
.PHONY: all clean fclean re run
