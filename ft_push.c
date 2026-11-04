/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallaire <lallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 11:01:56 by username          #+#    #+#             */
/*   Updated: 2026/11/04 09:46:04 by lallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push.h"

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

int	ft_pb(t_list **a, t_list **b)
{
	push(a, b);
	ft_printf("%s\n", "pb");
	return (1);
}

int	ft_pa(t_list **a, t_list **b)
{
	push(b, a);
	ft_printf("%s\n", "pa");
	return (1);
}
