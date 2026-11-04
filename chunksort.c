/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallaire <lallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:07:13 by username          #+#    #+#             */
/*   Updated: 2026/11/04 13:11:30 by lallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	get_max_pos(t_list *b)
{
	int	max;
	int	pos;
	int	max_pos;

	max = b->index;
	pos = 0;
	max_pos = 0;
	while (b)
	{
		if (b->index > max)
		{
			max = b->index;
			max_pos = pos;
		}
		pos++;
		b = b->pile;
	}
	return (max_pos);
}

void	push_max_to_a(t_list **a, t_list **b)
{
	int	pos;
	int	size;

	pos = get_max_pos(*b);
	size = ft_lstsize(*b);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			lst_down(b, 'b');
	}
	else
	{
		while (pos++ < size)
			lst_up(b, 'b');
	}
	ft_pa(a, b);
}

void	push_chunks(t_list **a, t_list **b, int chunk_size)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			ft_pb(a, b);
			lst_down(b, 'b');
			i++;
		}
		else if ((*a)->index <= i + chunk_size)
		{
			ft_pb(a, b);
			i++;
		}
		else
			lst_down(a, 'a');
	}
}

void	chunk_sort(t_list **a, t_list **b)
{
	int	size;
	int	nb_chunks;

	ft_order66(a);
	size = ft_lstsize(*a);
	nb_chunks = size / 66 + 4;
	push_chunks(a, b, size / nb_chunks);
	while (*b)
		push_max_to_a(a, b);
}
