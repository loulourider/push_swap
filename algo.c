/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallaire <lallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:01:09 by username          #+#    #+#             */
/*   Updated: 2026/11/04 13:11:11 by lallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include "ft_printf.h"

void	ft_order66(t_list **a)
{
	t_list	*cur;
	t_list	*cmp;
	int		count;

	cur = *a;
	while (cur)
	{
		count = 0;
		cmp = *a;
		while (cmp)
		{
			if (cmp->chiffre < cur->chiffre)
				count++;
			cmp = cmp->pile;
		}
		cur->index = count;
		cur = cur->pile;
	}
}
