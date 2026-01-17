NAME        = fragtrap
CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98

SRCS        = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJS        = $(SRCS:.cpp=.o)

GREEN       = \033[1;32m
YELLOW      = \033[1;33m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Linking objects...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)FragTrap Ready! Run ./$(NAME)$(RESET)"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re