/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 02:30:37 by akaraban          #+#    #+#             */
/*   Updated: 2023/03/10 05:37:05 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	i;

	i = 0;
	while (*str)
		i = (i * 10) + (*str++ - '0');
	return (i);
}

void	ft_important(int signal, siginfo_t *info, void *unused)
{
	(void)signal;
	(void)info;
	(void)unused;
	write(1, "message sent\n", 13);
}

void	ft_client(int pid_number, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[2][j])
	{
		i = 7;
		while (i >= 0)
		{
			if (argv[2][j] >> i & 1)
				kill(pid_number, SIGUSR1);
			else
				kill(pid_number, SIGUSR2);
			i--;
			usleep(50);
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	int					pid_number;
	struct sigaction	come;

	come.sa_flags = SA_SIGINFO;
	come.sa_sigaction = ft_important;
	sigaction(SIGUSR2, &come, 0);
	if (argc == 3)
	{
		pid_number = ft_atoi(argv[1]);
		ft_client(pid_number, argv);
	}
}