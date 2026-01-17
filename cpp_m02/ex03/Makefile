# ==========================================
#              CONFIG
# ==========================================

NAME        = bsp
CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98

# Список твоих файлов .cpp
SRCS        = main.cpp Fixed.cpp Point.cpp bsp.cpp

# Превращаем список .cpp в список .o
OBJS        = $(SRCS:.cpp=.o)

# Цвета для вывода (красота в консоли)
GREEN       = \033[1;32m
RED         = \033[1;31m
YELLOW      = \033[1;33m
RESET       = \033[0m

# ==========================================
#              RULES
# ==========================================
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Linking objects...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Build successful! Run ./$(NAME)$(RESET)"

%.o: %.cpp
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	rm -f $(OBJS)


fclean: clean
	@echo "$(RED)Cleaning executable...$(RESET)"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re