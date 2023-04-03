# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 03:02:19 by akaraban          #+#    #+#              #
#    Updated: 2023/03/27 18:41:21 by akaraban         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SRCSERVER = server.c
SRCCLIENT = client.c

CC = gcc
FLAGS = -Wall -Wextra -Werror -I$(PRINTF)/headers -L$(PRINTF) -lftprintf

PRINTF = ft_printf

GREEN = \033[0;32m
RESET = \033[0m

all:
	@make -s -C $(PRINTF)
	@gcc $(FLAGS) $(SRCSERVER) -o $(SERVER)
	@gcc $(FLAGS) $(SRCCLIENT) -o $(CLIENT)
	@echo "$(GREEN)Success:$(RESET) Server and Client are Created"


clean:
	@make clean -s -C $(PRINTF)

fclean: clean
	@make fclean -s -C $(PRINTF)
	@rm -f $(SERVER) $(CLIENT)
	@echo "$(GREEN)Success:$(RESET) Server and Client Have Been Cleaned"

re: fclean all