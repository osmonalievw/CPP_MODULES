NAME        = animal
CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98 -I include

SRC_DIR     = srcs/
OBJ_DIR     = obj/

SRC_FILES   = Animal.cpp Cat.cpp Dog.cpp Brain.cpp WrongAnimal.cpp
OBJS        = $(OBJ_DIR)main.o $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))

GREEN       = \033[1;32m
YELLOW      = \033[1;33m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Linking objects...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Compilation successful! Run ./$(NAME)$(RESET)"

$(OBJ_DIR)main.o: main.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning objects...$(RESET)"
	rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(YELLOW)Cleaning executable...$(RESET)"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re