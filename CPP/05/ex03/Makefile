NAME = Interns
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors
SRC = main.cpp Bureacrat.cpp AForm.cpp PresidentialPardonForm.cpp \
	  RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
CXX = clang++
HDR = Bureacrat.hpp AForm.hpp PresidentialPardonForm.hpp \
	  RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Intern.hpp
OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(HDR)
	@$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)
clean:
	@rm -f *.o
	@rm -f *_shrubbery
fclean: clean
	@rm -f $(NAME)
re: fclean all

run: all
	@./$(NAME)

.PHONY: all clean fclean re run
