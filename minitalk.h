/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 05:25:39 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/04 00:41:05 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include "ft_printf/ft_printf.h"

# define RED     "\033[1;31m"
# define GREEN   "\x1b[32m"
# define RESET   "\x1b[0m"

# define BITS_PER_BYTE 8
# define BIT_MASK 1

int		ft_atoi(char *str);
void	ft_send_bits(int pid, char byte);
void	ft_signal_translation(int signal);
void	display_banner(void);

#endif
