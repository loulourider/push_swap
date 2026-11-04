/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallaire <lallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 14:32:36 by username          #+#    #+#             */
/*   Updated: 2026/11/04 10:56:31 by lallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include "ft_printf.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count += 1;
		lst = lst->pile;
	}
	return (count);
}

static int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static int	radix_pass(t_list **a, t_list **b, int size, int bit)
{
	int	count;
	int	j;

	count = 0;
	j = 0;
	while (j < size)
	{
		if ((((*a)->index >> bit) & 1) == 0)
			count += ft_pb(a, b);
		else
			count += lst_down(a, 'a');
		j++;
	}
	while (*b != NULL)
		count += ft_pa(a, b);
	return (count);
}

int	radix_sort(t_list **a, t_list **b)
{
	int	size;
	int	max_bits;
	int	i;
	int	count;

	size = ft_lstsize(*a);
	max_bits = get_max_bits(size);
	count = 0;
	i = 0;
	while (i < max_bits)
	{
		count += radix_pass(a, b, size, i);
		i++;
	}
	return (count);
}
