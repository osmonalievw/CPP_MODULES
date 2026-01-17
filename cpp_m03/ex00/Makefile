NAME        = claptrap
CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98

SRCS        = main.cpp ClapTrap.cpp
OBJS        = $(SRCS:.cpp=.o)

GREEN       = \033[1;32m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Compiled successfully! Run ./$(NAME)$(RESET)"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re