/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallaire <lallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:05:09 by username          #+#    #+#             */
/*   Updated: 2026/11/04 13:11:50 by lallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		result;

	if (!format)
		return (-1);
	result = 0;
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			result += ft_convert(format[i + 1], &args);
			i += 2;
		}
		else
		{
			result += write(1, &format[i], 1);
			i++;
		}
	}
	va_end(args);
	return (result);
}

int	ft_convert(char c, va_list *args)
{
	char	*base_maj;
	char	*base;

	base_maj = "0123456789ABCDEF";
	base = "0123456789abcdef";
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (c == 'p')
		return (ft_putmem(va_arg(*args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_putnbr_n(va_arg(*args, unsigned int)));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(*args, unsigned int), base));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(*args, unsigned int), base_maj));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}
