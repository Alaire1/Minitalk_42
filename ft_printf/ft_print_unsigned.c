/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:09:25 by akaraban          #+#    #+#             */
/*   Updated: 2023/01/30 21:53:43 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_nbr(unsigned int nbr)
{
	if (nbr > 9)
		ft_print_unsigned(nbr / 10);
	if (nbr <= 9)
	{
		ft_putchar(nbr + 48);
		return ;
	}
	ft_putchar((nbr % 10) + 48);
}

int	ft_print_unsigned(unsigned int nbr)
{
	unsigned int	i;

	i = 1;
	print_nbr(nbr);
	while (nbr > 9)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}
