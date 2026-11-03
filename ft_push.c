/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_push.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/03 11:01:56 by username         #+#    #+#              */
/*   Updated: 2026/11/03 12:56:39 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push.h"

static void	ftputstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

static void	push(t_list **src, t_list **dst)
{
	t_list	*tmp;

	if (!(*src))
		return ;
	tmp = *src;
	*src = (*src)->pile;
	tmp->pile = (*dst);
	(*dst) = tmp;
}

void	ft_pb(t_list **a, t_list **b)
{
	push(a, b);
	ftputstr("pb\n");
}

void	ft_pa(t_list **a, t_list **b)
{
	push(b, a);
	ftputstr("pa\n");
}
