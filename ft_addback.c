/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_addback.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/03 13:22:50 by username         #+#    #+#              */
/*   Updated: 2026/11/03 13:25:45 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include <stdio.h>

// void    ft_addback_a(t_list **a, int index)
// {
//     t_list *tmp;
//     t_list *new;

//     new = malloc(sizeof (t_list));
//     if (!new)
//         return ;
//     new->index = index;
//     new->pile = NULL;
//     if (!*(a))
//     {
//         *a = new;
//         return ;
//     }
//     tmp = *a;
//     while (tmp->pile != NULL)
//         tmp = tmp->pile;
//     tmp->pile = new;
// }

void	lst_up(t_list **lst)
{
	t_list	*prev;
	t_list	*last;

	if (!lst || !*lst || !(*lst)->pile)
		return ;
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
}
<<<<<<< HEAD
=======


void ft_addback_b(t_list **b)
{
    t_list *tamp;
    tamp = *a
}
>>>>>>> 715a61f (try down)
