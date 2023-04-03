/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:18:50 by akaraban          #+#    #+#             */
/*   Updated: 2023/02/13 18:42:52 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_hex_len(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}

static char	*hex_to_str(unsigned int nbr, char *base)
{
	int		size;
	char	*hex_str;

	size = ft_count_hex_len(nbr);
	hex_str = (char *)malloc(sizeof(char) * (size + 1));
	if (!hex_str)
		return (NULL);
	hex_str[size] = '\0';
	while (size > 0)
	{
		hex_str[size - 1] = base[nbr % 16];
		nbr = nbr / 16;
		size--;
	}
	return (hex_str);
}

int	ft_print_hex(unsigned int nbr, char const character)
{
	char	*str;
	int		len;
	char	*base_big;
	char	*base_small;

	base_big = "0123456789ABCDEF";
	base_small = "0123456789abcdef";
	if (character == 'X')
		str = hex_to_str(nbr, base_big);
	else
		str = hex_to_str(nbr, base_small);
	len = ft_putstr(str);
	free(str);
	return (len);
}
