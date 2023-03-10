/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 02:30:39 by akaraban          #+#    #+#             */
/*   Updated: 2023/03/10 07:04:12 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	display_banner(void)
{
	ft_printf("%s｡☆✼★━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━★✼☆｡%s\n", MAGENTA, RESET);
	write(1, "M       M IIIIIII N      N IIIIIII\n", 35);
    write(1, "MM     MM    I    N N    N    I   \n", 35);
    write(1, "M M   M M    I    N  N   N    I   \n", 35);
    write(1, "M  M M  M    I    N   N  N    I   \n", 35);
    write(1, "M   M   M    I    N    N N    I   \n", 35);
    write(1, "M       M    I    N     NN    I   \n", 35);
    write(1, "M       M IIIIIII N      N IIIIIII\n", 35);
    write(1, "\t\t\t   TTTTTTT     A     L       K    K \n", 42);
	write(1, "\t\t      T       A A    L       K   K  \n", 41);
	write(1, "\t\t      T      A   A   L       K  K   \n", 41);
	write(1, "\t\t      T     AAAAAAA  L       K K    \n", 41);
	write(1, "\t\t      T    A       A L       K  K   \n", 41);
	write(1, "\t\t      T    A       A L       K   K  \n", 41);
	write(1, "\t\t      T    A       A LLLLLLL K    K \n", 40);
	ft_printf("%s｡☆✼★━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━★✼☆｡%s\n", MAGENTA, RESET);
}

void	ft_putnbr(int nbr)
{
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	write (1, &"0123456789"[nbr % 10], 1);
}

void	ft_server(int signal, siginfo_t *info, void *unused)
{
	static int	i = 128;
	static char	c = 0;

	(void)unused;
	if (signal == SIGUSR1)
		c = c | i;
	i /= 2;
	if (i == 0)
	{
		write(1, &c, 1);
		i = 128;
		c = 0;
		if (kill(info->si_pid, SIGUSR2) == -1)
			write(1, "Error signal\n", 15);
	}
}

int	main(void)
{
	struct sigaction	signal;
	int					pid;

    display_banner();
	signal.sa_flags = SA_SIGINFO;
	signal.sa_sigaction = ft_server;
	if (sigaction(SIGUSR1, &signal, 0) == -1)
		write(1, "Error has occurred\n", 15);
	if (sigaction(SIGUSR2, &signal, 0) == -1)
		write(1, "Error has occured\n", 15);
	pid = getpid();
	write(1, "Server PID: ", 13);
	ft_putnbr(pid);
	write(1, "\n", 1);
	while(1)
		;
}
