/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsezgin <gsezgin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:15:53 by gsezgin           #+#    #+#             */
/*   Updated: 2024/12/10 12:03:41 by gsezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_type_control(const char c, va_list arg);
int	ft_printf(const char *str, ...);
int	ft_printchar(char c);
int	ft_printstr(char *str);
int	ft_printnbr(int num);
int	ft_printnbr_u(unsigned int num);
int	ft_address(unsigned long n);
int	ft_base_convert(unsigned long n, char c);

#endif
