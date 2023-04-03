/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 02:30:39 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/03 22:56:55 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	display_banner(void)
{
	ft_printf("%s｡☆✼★━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━★✼☆｡%s\n", MAGENTA, RESET);
	ft_printf("M       M IIIIIII N      N IIIIIII\n");
    ft_printf("MM     MM    I    N N    N    I   \n");
    ft_printf("M M   M M    I    N  N   N    I   \n");
    ft_printf("M  M M  M    I    N   N  N    I   \n");
    ft_printf("M   M   M    I    N    N N    I   \n");
    ft_printf("M       M    I    N     NN    I   \n");
    ft_printf("M       M IIIIIII N      N IIIIIII\n");
    ft_printf("\t  TTTTTTT     A     L       K    K \n");
	ft_printf("\t     T       A A    L       K   K  \n");
	ft_printf("\t     T      A   A   L       K  K   \n");
	ft_printf("\t     T     AAAAAAA  L       K K    \n");
	ft_printf("\t     T    A       A L       K  K   \n");
	ft_printf("\t     T    A       A L       K   K  \n");
	ft_printf("\t     T    A       A LLLLLLL K    K \n");
	ft_printf("%s｡☆✼★━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━★✼☆｡%s\n", MAGENTA, RESET);
}

void	ft_signal_translation(int signal)
{
	static int	current_bit;
	static int	byte_accumulator;

	if (signal == SIGUSR1)
		byte_accumulator |= (0x01 << current_bit);
	current_bit++;
	if (current_bit == BITS_PER_BYTE)
	{
		ft_printf("%c", byte_accumulator);
		current_bit = 0;
		byte_accumulator = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	display_banner();
	pid = getpid();
	ft_printf("%sServer PID: %s%i\n", MAGENTA, RESET, pid);
	ft_printf("%sWaiting for a message...%s\n", GREY, RESET);
	while (argc == 1)
	{
		signal(SIGUSR1, ft_signal_translation);
		signal(SIGUSR2, ft_signal_translation);
		pause ();
	}
	return (0);
}
