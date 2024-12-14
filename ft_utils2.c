/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsezgin <gsezgin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:42:31 by gsezgin           #+#    #+#             */
/*   Updated: 2024/12/14 12:57:25 by gsezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_address(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		len += ft_printstr("(nil)");
	}
	else
	{
		len += ft_printstr("0x");
		len += ft_base_convert(n, 'x');
	}
	return (len);
}

int	ft_base_convert(unsigned long n, char c)
{
	int		len;
	char	*base;

	len = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		len += ft_base_convert(n / 16, c);
		len += ft_printchar(base[n % 16]);
	}
	else
	{
		len += ft_printchar(base[n % 16]);
	}
	return (len);
}
