/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallaire <lallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:22:35 by username          #+#    #+#             */
/*   Updated: 2026/11/04 12:03:21 by lallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push.h"

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

static int	parse_flag(char *arg)
{
	// if (!ft_strcmp(arg, "--simple"))
	// 	return (ALGO_SIMPLE);
	if (!ft_strcmp(arg, "--medium"))
		return (ALGO_MEDIUM);
	if (!ft_strcmp(arg, "--complex"))
		return (ALGO_COMPLEX);
	return (0);
}

static void	fill_stack(t_list **a, int argc, char **argv, int i)
{
	while (i < argc)
		ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i++])));
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		strategy;

	a = NULL;
	b = NULL;
	strategy = 0;
	if (argc > 1)
		strategy = parse_flag(argv[1]);
	fill_stack(&a, argc, argv, 1 + (strategy != 0));
	if (ft_lstsize(a) > 1)
		run_algo(&a, &b, strategy);
	return (0);
}
