CC := c++
CFLAGS := -Wall -Wextra -Werror
TARGET := a.out

SRCS := ASpell.cpp	\
		ATarget.cpp	\
		Dummy.cpp	\
		Fwoosh.cpp	\
		main.cpp	\
		Warlock.cpp	\
		BrickWall.cpp	\
		Fireball.cpp	\
		Polymorph.cpp	\
		SpellBook.cpp	\
		TargetGenerator.cpp	\

OBJS := $(SRCS:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(TARGET)

re:
	fclean all

.PHONY: all clean fclean re