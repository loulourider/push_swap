/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   tools1.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/28 15:07:22 by username         #+#    #+#              */
/*   Updated: 2026/11/03 12:48:12 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long n, char *base)
{
	int				count;
	unsigned long	len;

	count = 0;
	len = 0;
	while (base[len])
		len++;
	if (n >= len)
		count += ft_putnbr_base(n / len, base);
	count += ft_putchar(base[n % len]);
	return (count);
}

static int	ft_puthex(unsigned long n)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16);
	count += write(1, &base[n % 16], 1);
	return (count);
}

int	ft_putmem(void *ptr)
{
	int	count;

	if (!ptr)
		return (write(1, "(nil)", 5));
	count = write(1, "0x", 2);
	count += ft_puthex((unsigned long) ptr);
	return (count);
}

int	in_range(char *s)
{
	long	n;
	int		sign;
	int		i;

	n = 0;
	sign = 1;
	i = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		n = n * 10 + (s[i] - '0');
		if (n * sign > INT_MAX || n * sign < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}
