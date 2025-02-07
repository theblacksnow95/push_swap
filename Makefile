NAME = push_test
CC = gcc
SRC = src/parsing.c src/push_swap.c src/utils.c src/ft_atol.c
LIBFT_DIR = lib/libft
LIBFT_LIB = libft.a
C_FLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)
L_FLAGS = -L$(LIBFT_DIR) -lft
BIN_DIR = bin
OBJ_DIR = obj

# ANSI Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(C_FLAGS) -c $< -o $@ 2> .error_log && \
	(echo "$(GREEN)Compiled: $< [OK]$(RESET)") || \
	(echo "$(RED)Error compiling: $< [KO]$(RESET)" && cat .error_log && rm -f .error_log && exit 1)

TARGET = $(BIN_DIR)/push_test

all: $(TARGET)

$(TARGET): $(OBJ) $(LIBFT_DIR)/$(LIBFT_LIB)
	@echo "$(YELLOW)Buiding target and objects...$(RESET)"
	@mkdir -p $(BIN_DIR)
	@$(CC) $(C_FLAGS) $(OBJ) -o $(TARGET) $(L_FLAGS) 2> .error_log && \
	(echo "Binary: $(GREEN)[OK]$(RESET)") || \
	(echo "Binary: $(RED)[KO]$(RESET)" && cat .error_log && rm -f .error_log && exit 1)

$(LIBFT_DIR)/$(LIBFT_LIB):
	@echo "$(YELLOW)Building libft library...$(RESET)"
	@$(MAKE) bonus -C $(LIBFT_DIR) 2> .error_log && \
	(echo "Libft: $(GREEN)[OK]$(RESET)") || \
	(echo "Libft: $(RED)[KO]$(RESET)" && cat .error_log && rm -f .error_log && exit 1)

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean >/dev/null 2>&1
	@echo "Objects cleaned: $(GREEN)[OK]$(RESET)"

fclean: clean
	rm -f $(TARGET)
	@$(MAKE) -C $(LIBFT_DIR) fclean >/dev/null 2>&1
	@echo "Binary and library cleaned: $(GREEN)[OK]$(RESET)"

re: clean all

.PHONY: all clean fclean re
