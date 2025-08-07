# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 18:37:54 by vde-maga          #+#    #+#              #
#    Updated: 2025/07/29 18:47:08 by vde-maga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------- Variables ---------------------------------------------
CC        = cc
CFLAGS    = -Wall -Wextra -Werror -I$(INC_DIR)

SRC_DIR   = srcs
OBJ_DIR   = objs
INC_DIR   = includes

# Executables
CLIENT        = client
SERVER        = server
CLIENT_BONUS  = client_bonus
SERVER_BONUS  = server_bonus

# SRCs Files
SRC_UTILS         = $(SRC_DIR)/utils/utils.c
SRC_CLIENT        = $(SRC_DIR)/client.c
SRC_SERVER        = $(SRC_DIR)/server.c
SRC_CLIENT_BONUS  = $(SRC_DIR)/bonus/client_bonus.c
SRC_SERVER_BONUS  = $(SRC_DIR)/bonus/server_bonus.c

# OBJs Files
OBJ_UTILS         = $(OBJ_DIR)/utils/utils.o
OBJ_CLIENT        = $(OBJ_DIR)/client.o
OBJ_SERVER        = $(OBJ_DIR)/server.o
OBJ_CLIENT_BONUS  = $(OBJ_DIR)/bonus/client_bonus.o
OBJ_SERVER_BONUS  = $(OBJ_DIR)/bonus/server_bonus.o

CLIENT_OBJS       = $(OBJ_CLIENT) $(OBJ_UTILS)
SERVER_OBJS       = $(OBJ_SERVER) $(OBJ_UTILS)
CLIENT_BONUS_OBJS = $(OBJ_CLIENT_BONUS) $(OBJ_UTILS)
SERVER_BONUS_OBJS = $(OBJ_SERVER_BONUS) $(OBJ_UTILS)

# Colors
GREEN   = \033[0;32m
RED     = \033[0;31m
YELLOW  = \033[0;33m
CYAN    = \033[0;36m
RESET   = \033[0m

# ---------------------- Default -----------------------------------------------

all: $(CLIENT) $(SERVER)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

# ---------------------- Linking -----------------------------------------------

$(CLIENT): $(CLIENT_OBJS)
	@echo ""
	@echo "$(YELLOW)Linking $@...$(RESET)"
	$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)Done! Execute ./$@$(RESET)"

$(SERVER): $(SERVER_OBJS)
	@echo ""
	@echo "$(YELLOW)Linking $@...$(RESET)"
	$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)Done! Execute ./$@$(RESET)"

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJS)
	@echo ""
	@echo "$(YELLOW)Linking $@...$(RESET)"
	$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)Done! Execute ./$@$(RESET)"

$(SERVER_BONUS): $(SERVER_BONUS_OBJS)
	@echo ""
	@echo "$(YELLOW)Linking $@...$(RESET)"
	$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)Done! Execute ./$@$(RESET)"

# ---------------------- Compiling ---------------------------------------------

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(CYAN)Compiling $< → $@$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

# ---------------------- Cleaning ----------------------------------------------

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Removing executables...$(RESET)"
	@rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
