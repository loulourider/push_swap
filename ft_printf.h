/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/28 13:52:59 by username         #+#    #+#              */
/*   Updated: 2026/11/03 12:45:08 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int	ft_printf(const char *format, ...);
int	ft_putmem(void *ptr);
int	ft_putnbr(int nb);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_putnbr_base(unsigned long n, char *base);
int	ft_convert(char c, va_list *args);
int	ft_putnbr_n(unsigned int n);

#endif
