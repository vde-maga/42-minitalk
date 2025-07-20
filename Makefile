# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 18:37:54 by vde-maga          #+#    #+#              #
#    Updated: 2025/07/16 18:37:54 by vde-maga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(PRINT_PATH)
CLIENT_SRCS = srcs/client.c
SERVER_SRCS = srcs/server.c
CLIENT_BONUS_SRCS = srcs/client_bonus.c
SERVER_BONUS_SRCS = srcs/server_bonus.c
PRINT_PATH = srcs/ft_printf
PRINT_ARCHIVE = $(PRINT_PATH)/libftprintf.a
CLIENT_NAME = client
SERVER_NAME = server
CLIENT_BONUS_NAME = client_bonus
SERVER_BONUS_NAME = server_bonus

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_SRCS) $(PRINT_ARCHIVE)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_SRCS) -L$(PRINT_PATH) -lftprintf

$(SERVER_NAME): $(SERVER_SRCS) $(PRINT_ARCHIVE)
	$(CC) $(CFLAGS) -o $@ $(SERVER_SRCS) -L$(PRINT_PATH) -lftprintf

$(CLIENT_BONUS_NAME): $(CLIENT_BONUS_SRCS) $(PRINT_ARCHIVE)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_BONUS_SRCS) -L$(PRINT_PATH) -lftprintf

$(SERVER_BONUS_NAME): $(SERVER_BONUS_SRCS) $(PRINT_ARCHIVE)
	$(CC) $(CFLAGS) -o $@ $(SERVER_BONUS_SRCS) -L$(PRINT_PATH) -lftprintf

$(PRINT_ARCHIVE):
	$(MAKE) -C $(PRINT_PATH)

clean:
	$(MAKE) -C $(PRINT_PATH) clean

fclean: clean
	$(MAKE) -C $(PRINT_PATH) fclean
	rm -f $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)

re: fclean all

bonus: $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)

.PHONY: all clean fclean re bonus

