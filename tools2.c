/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   tools2.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/28 15:06:20 by username         #+#    #+#              */
/*   Updated: 2026/10/29 11:23:36 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		ft_putchar((str[i]));
		i++;
	}
	return (i);
}

int	ft_putnbr_n(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putnbr_n(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

int	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
		return (ft_putchar('-') + ft_putnbr(-nb));
	if (nb < 10)
		return (ft_putchar('0' + nb));
	return (ft_putnbr(nb / 10) + ft_putnbr(nb % 10));
}
