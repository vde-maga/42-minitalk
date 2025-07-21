# **************************************************************************** #
:#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 18:37:54 by vde-maga          #+#    #+#              #
#    Updated: 2025/07/21 17:58:34 by vde-maga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------- Variables ----------------------

CC        = cc
CFLAGS    = -Wall -Wextra -Werror

SRC_DIR   = srcs
OBJ_DIR   = objs

CLIENT_SRCS        = $(SRC_DIR)/client.c
SERVER_SRCS        = $(SRC_DIR)/server.c
CLIENT_BONUS_SRCS  = $(SRC_DIR)/client_bonus.c
SERVER_BONUS_SRCS  = $(SRC_DIR)/server_bonus.c

CLIENT_OBJS        = $(OBJ_DIR)/client.o
SERVER_OBJS        = $(OBJ_DIR)/server.o
CLIENT_BONUS_OBJS  = $(OBJ_DIR)/client_bonus.o
SERVER_BONUS_OBJS  = $(OBJ_DIR)/server_bonus.o

CLIENT_NAME        = client
SERVER_NAME        = server
CLIENT_BONUS_NAME  = client_bonus
SERVER_BONUS_NAME  = server_bonus

# coloração
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
CYAN = \033[0;36m
MAGENTA = \033[0;35m
BOLD = \033[1m
RESET = \033[0m

# ---------------------- Phonies ------------------------

.PHONY: all bonus clean fclean re

# ---------------------- Default ------------------------

all: $(CLIENT_NAME) $(SERVER_NAME)

# ---------------------- Linking Rules ------------------

$(CLIENT_NAME): $(CLIENT_OBJS)
	@echo ""
	@echo "$(YELLOW)  Linking $(CLIENT_NAME)...$(RESET)"
	$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)  Done! Run with ./$@$(RESET)"

$(SERVER_NAME): $(SERVER_OBJS)
	@echo ""
	@echo "$(YELLOW)  Linking $(SERVER_NAME)...$(RESET)"
	$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)  Done! Run with ./$@$(RESET)"

bonus: $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)

$(CLIENT_BONUS_NAME): $(CLIENT_BONUS_OBJS)
	@echo ""
	@echo "$(YELLOW)  Linking $(CLIENT_BONUS_NAME)...$(RESET)"
	$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)  Done! Run with ./$@$(RESET)"

$(SERVER_BONUS_NAME): $(SERVER_BONUS_OBJS)
	@echo ""
	@echo "$(YELLOW)  Linking $(SERVER_BONUS_NAME)...$(RESET)"
	$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)  Done! Run with ./$@$(RESET)"

# ---------------------- Compilation Rule --------------

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(CYAN)  Compiling $< → $@$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

# ---------------------- Cleaning -----------------------

clean:
	@echo "$(RED)  Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)  Removing executables...$(RESET)"
	@rm -f $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)

re: fclean all
