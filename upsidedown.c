/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upsidedown.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallaire <lallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:22:50 by username          #+#    #+#             */
/*   Updated: 2026/11/04 09:37:53 by lallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include "ft_printf.h"

int	lst_up(t_list **lst, char c)
{
	t_list	*prev;
	t_list	*last;

	if (!lst || !*lst || !(*lst)->pile)
		return (0);
	prev = NULL;
	last = *lst;
	while (last->pile)
	{
		prev = last;
		last = last->pile;
	}
	prev->pile = NULL;
	last->pile = *lst;
	*lst = last;
	ft_printf("%s%c\n", "rr", c);
	return (1);
}

int	lst_down(t_list **lst, char c)
{
	t_list	*first;
	t_list	*last;

	if (!lst || !*lst || !(*lst)->pile)
		return (0);
	first = *lst;
	last = *lst;
	while (last->pile)
		last = last->pile;
	*lst = first->pile;
	first->pile = NULL;
	last->pile = first;
	ft_printf("%s%c\n", "r", c);
	return (1);
}
