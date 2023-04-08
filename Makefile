# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 18:21:08 by akaraban          #+#    #+#              #
#    Updated: 2023/04/08 19:18:03 by akaraban         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
PRINTF = ft_printf/libftprintf.a

CC = gcc

SRC_SERVER = server.c
SRC_CLIENT = client.c

OBJS = server.o client.o

CFLAGS = -Wall -Wextra -Werror

GREEN = \033[0;32m
RESET = \033[0m
	
all: $(SERVER) $(CLIENT)
	@echo "$(GREEN)Success: $(RESET)Server and Client are Created"

$(SERVER): $(PRINTF)
	@$(CC) $(CFLAGS) $(PRINTF) $(SRC_SERVER) -o $(SERVER)

$(CLIENT): $(PRINTF)
	@$(CC) $(CFLAGS) $(PRINTF) $(SRC_CLIENT) -o $(CLIENT)

$(PRINTF):
	@make -C ft_printf

clean :
	@make clean -C ft_printf
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(PRINTF)
	@rm -rf $(SERVER) $(CLIENT)
	@echo "$(GREEN)Success: $(RESET) Server and Client Have Been Cleaned"

re : fclean all

.PHONY: all clean fclean re
