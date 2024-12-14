/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsezgin <gsezgin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:23:53 by gsezgin           #+#    #+#             */
/*   Updated: 2024/12/10 16:44:52 by gsezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printnbr(int num)
{
	int		len;
	long	nbr;

	nbr = num;
	len = 0;
	if (nbr < 0)
	{
		len += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		len += ft_printnbr(nbr / 10);
		len += ft_printchar(nbr % 10 + '0');
	}
	else
	{
		len += ft_printchar(nbr % 10 + '0');
	}
	return (len);
}

int	ft_printnbr_u(unsigned int num)
{
	int	len;

	len = 0;
	if (num <= 9)
	{
		len += ft_printchar(num + '0');
	}
	else
	{
		len += ft_printnbr_u(num / 10);
		len += ft_printchar(num % 10 + '0');
	}
	return (len);
}
