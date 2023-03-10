/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:59:14 by akaraban          #+#    #+#             */
/*   Updated: 2023/02/15 21:19:42 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_arg(const char *string, va_list args, int i)
{
	if (string[i] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (string[i] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (string[i] == 'p')
		return (write(1, "0x", 2) + ft_print_pointer(va_arg(args, void *)));
	else if (string[i] == 'd' || string[i] == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (string[i] == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (string[i] == 'X' || string[i] == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), string[i]));
	else if (string[i] == '%')
		return (write(1, "%", 1));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		result;

	i = 0;
	result = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			result += ft_printf_arg(str, args, i + 1);
			i++;
		}
		else
			result += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (result);
}
