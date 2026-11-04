/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallaire <lallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 09:54:54 by username          #+#    #+#             */
/*   Updated: 2026/11/04 12:02:36 by lallaire         ###   ########.fr       */
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
	if (pairs == 0)
		return (0);
	return ((int)(mistakes * 10000 / pairs));
}

int	choose_algo(int strategy, int disorder)
{
	if (strategy != 0)
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
		simple_sort(a, b);
	else if (strategy == ALGO_MEDIUM)
		chunk_sort(a, b);
	else
		radix_sort(a, b);
}
