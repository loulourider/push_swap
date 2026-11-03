/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   creat_stack.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/03 10:29:29 by username         #+#    #+#              */
/*   Updated: 2026/11/03 12:46:47 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include "ft_printf.h"

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

static int	is_correct(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	parsing(int argc, char **argv)
{
	int	j;

	j = 1;
	while (j < argc)
	{
		if (!is_correct(argv[j]) || !in_range(argv[j]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		j++;
	}
	return (1);
}
