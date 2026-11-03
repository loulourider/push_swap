/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   creat_stack.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/03 10:29:29 by username         #+#    #+#              */
/*   Updated: 2026/11/03 10:53:47 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include "printf.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	while (*lst)
	{
		lst = &(*lst)->pile;
	}
	(*lst) = new;
}

t_list	*ft_lstnew(int content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->chiffre = content;
	node->pile = NULL;
	node->index = 0;
	return (node);
}

t_list	*creat_stack(int *nbrs, int size)
{
	t_list	*stack;
	t_list	*node;
	int		i;

	stack = NULL;
	i = 0;
	while (i < size)
	{
		node = ft_lstnew(nbrs[i]);
		if (!node)
			return (NULL);
		ft_lstadd_back(&stack, node);
		i++;
	}
	return (stack);
}

// int	main(void)
// {
// 	int	nbrs[] =
// 	{
// 		1, 7, 3, 6, 2, 9, 0,
// 	};
// 	t_list	*a;
// 	t_list	*b = NULL;

// 	a = creat_stack(nbrs, 7);
// 	print_stacks(a, b);
// }
