# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 13:08:28 by akaraban          #+#    #+#              #
#    Updated: 2023/03/14 01:18:42 by akaraban         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

AR = ar

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

ARFLAGS = rc

SRCFILES =	ft_print_nbr.c \
			ft_print_hex.c \
			ft_print_pointer.c \
			ft_putstr.c \
			ft_printf.c \
			ft_strlen.c \
			ft_print_unsigned.c \
			ft_strchr.c 
			

OBJFILES = ${SRCFILES:.c=.o}

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJFILES)
	$(AR) $(ARFLAGS) $(NAME) $(OBJFILES)

all : $(NAME)

fclean : clean
	rm -rf $(NAME)

clean :
	rm -rf $(OBJFILES)

re : fclean $(NAME)
