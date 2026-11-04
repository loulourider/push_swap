/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallaire <lallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 13:11:06 by username          #+#    #+#             */
/*   Updated: 2026/11/04 16:27:08 by lallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	compute_disorder(t_list *a)
{
	t_list	*cur;
	t_list	*cmp;
	long	mistakes;
	long	pairs;

	mistakes = 0;
	pairs = 0;
	cur = a;
	while (cur)
	{
		cmp = cur->pile;
		while (cmp)
		{
			pairs++;
			if (cur->chiffre > cmp->chiffre)
				mistakes++;
			cmp = cmp->pile;
		}
		cur = cur->pile;
	}
	if (!pairs)
		return (0);
	return ((int)(mistakes * 10000 / pairs));
}

int	is_sorted(t_list *a)
{
	while (a && a->pile)
	{
		if (a->chiffre > a->pile->chiffre)
			return (0);
		a = a->pile;
	}
	return (1);
}

int	choose_algo(int strategy, int disorder)
{
	if (strategy)
		return (strategy);
	if (disorder < 2000)
		return (ALGO_SIMPLE);
	if (disorder < 5000)
		return (ALGO_MEDIUM);
	return (ALGO_COMPLEX);
}

void	run_algo(t_list **a, t_list **b, int strategy)
{
	strategy = choose_algo(strategy, compute_disorder(*a));
	if (strategy == ALGO_SIMPLE)
		tri_selectif(a, b);
	else if (strategy == ALGO_MEDIUM)
		radix_sort(a, b);
	else if (strategy == ALGO_COMPLEX)
		chunk_sort(a, b);
}
