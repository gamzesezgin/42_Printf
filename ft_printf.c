/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsezgin <gsezgin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:14:25 by gsezgin           #+#    #+#             */
/*   Updated: 2024/12/14 11:52:40 by gsezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_control(const char c, va_list args)
{
	int				sum;

	sum = 0;
	if (c == 'c')
		sum += ft_printchar(va_arg(args, int));
	else if (c == 's')
		sum += ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		sum += ft_address(va_arg(args, unsigned long));
	else if (c == 'd' || c == 'i')
		sum += ft_printnbr(va_arg(args, int));
	else if (c == 'u')
		sum += ft_printnbr_u(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		sum += ft_base_convert(va_arg(args, unsigned int), c);
	else if (c == '%')
		sum += ft_printchar('%');
	return (sum);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		total_length;
	int		i;

	va_start(args, str);
	i = 0;
	total_length = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while (str[i] == ' ' && str[i])
				i++;
			total_length += ft_type_control(str[i], args);
		}
		else
		{
			total_length += ft_printchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (total_length);
}
