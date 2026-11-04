/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallaire <lallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:29:29 by username          #+#    #+#             */
/*   Updated: 2026/11/04 13:11:31 by lallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include "ft_printf.h"

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

static int	has_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
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
	if (has_duplicate(argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
