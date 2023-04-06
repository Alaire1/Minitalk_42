# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 03:02:19 by akaraban          #+#    #+#              #
#    Updated: 2023/04/06 13:40:44 by akaraban         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
PRINTF = ft_printf/libftprintf.a
PRINTF_DIR = ft_printf

SRCSERVER = server.c
SRCCLIENT = client.c

OBJSERVER = $(SRCSERVER:.c=.o)
OBJCLIENT = $(SRCCLIENT:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror -Ift_minitalk.h

GREEN = \033[0;32m
RESET = \033[0m

all: $(PRINTF) $(SERVER) $(CLIENT)
	@echo "$(GREEN)Success: $(RESET)Server and Client are Created"

$(SERVER): $(OBJSERVER)
	@$(CC) $(FLAGS) $(PRINTF) -o $@ $(OBJSERVER)

$(CLIENT): $(OBJCLIENT)
	@$(CC) $(FLAGS) $(PRINTF) -o $@ $(OBJCLIENT)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(PRINTF):
	@$(MAKE) -s -C $(PRINTF_DIR)

clean:
	@make clean -s -C $(PRINTF_DIR)
	@rm -f $(OBJSERVER) $(OBJCLIENT)

fclean:
	@make fclean -s -C $(PRINTF_DIR)
	@rm -f $(SERVER) $(CLIENT) $(PRINTF)
	@echo "$(GREEN)Success: $(RESET) Server and Client Have Been Cleaned"
re:
	fclean all

.PHONY: all clean fclean re

