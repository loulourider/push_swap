/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_slectif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallaire <lallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 13:15:04 by username          #+#    #+#             */
/*   Updated: 2026/11/04 16:57:11 by lallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static int	direction(t_list *lst)
{
	int		count;
	t_list	*pos;
	int		size;
	t_list	*min;

	min = find_min(lst);
	size = ft_lstsize(lst);
	count = 0;
	pos = lst;
	while (pos != min)
	{
		pos = pos->pile;
		count++;
	}
	if (count <= size - count)
		return (1);
	else
		return (0);
}

void	tri_selectif(t_list **a, t_list **b)
{
	t_list	*pos;
	int		move;

	while (*a != NULL)
	{
		pos = find_min(*a);
		move = direction(*a);
		if (move > 0)
		{
			while (pos != *a)
				lst_up(a, 'a');
		}
		else
		{
			while (pos != *a)
				lst_down(a, 'a');
		}
		ft_pb(a, b);
	}
	while (*b != NULL)
		ft_pa(a, b);
}
