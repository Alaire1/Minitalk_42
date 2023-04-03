/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 02:30:37 by akaraban          #+#    #+#             */
/*   Updated: 2023/03/23 08:38:05 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (-1);
		i = (i * 10) + (*str++ - '0');
	}
	return (i);
}

void ft_send_bits(int pid, char byte)
{
	int	bit;

    if (pid <= 0)
        return;
    if (signal(SIGUSR1, SIG_IGN) == SIG_ERR 
	|| signal(SIGUSR2, SIG_IGN) == SIG_ERR) 
		return;
    bit = 0;
    while (bit < BITS_PER_BYTE) 
	{
        char current_bit = byte & (BIT_MASK << bit);
        if (current_bit) 
		{
            if (kill(pid, SIGUSR1) == -1) 
                return;
        } else 
		{
            if (kill(pid, SIGUSR2) == -1)
                return;
        }
        bit++;
        usleep(100);
    }
}
int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			ft_send_bits(pid, argv[2][i]);
			i++;
		}
		ft_send_bits(pid, '\n');
	}
	else
	{
		ft_printf("%sUse: ./program <PID> <message>%s\n", RED, RESET);
		return (1);
	}
	return (0);
}

