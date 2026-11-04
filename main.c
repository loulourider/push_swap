/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallaire <lallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 13:24:26 by username          #+#    #+#             */
/*   Updated: 2026/11/04 13:28:55 by lallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static int	parse_flag(char *arg)
{
	if (!ft_strcmp(arg, "--simple"))
		return (ALGO_SIMPLE);
	if (!ft_strcmp(arg, "--medium"))
		return (ALGO_MEDIUM);
	if (!ft_strcmp(arg, "--complex"))
		return (ALGO_COMPLEX);
	if (!ft_strcmp(arg, "--adaptive"))
		return (0);
	return (-1);
}

static int	is_number(char *s)
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

static int	valid_number(char *s)
{
	long long	n;
	long long	limit;
	int			sign;
	int			digit;
	int			i;

	i = 0;
	sign = 1;
	n = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i++] == '-')
			sign = -1;
	}
	limit = INT_MAX;
	if (sign < 0)
		limit = -(long long) INT_MIN;
	while (s[i])
	{
		digit = s[i++] - '0';
		if (n > (limit - digit) / 10)
			return (0);
		n = n * 10 + digit;
	}
	return (1);
}

static int	valid_arguments(int argc, char **argv, int first)
{
	int	i;
	int	j;

	i = first;
	while (i < argc)
	{
		if (!is_number(argv[i]) || !valid_number(argv[i]))
			return (0);
		j = first;
		while (j < i)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static t_list	*make_stack(int argc, char **argv, int first)
{
	t_list	*stack;
	t_list	*node;
	int		i;

	stack = NULL;
	i = first;
	while (i < argc)
	{
		node = ft_lstnew(ft_atoi(argv[i]));
		if (!node)
		{
			free_stack(stack);
			return (NULL);
		}
		ft_lstadd_back(&stack, node);
		i++;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		strategy;
	int		first;

	if (argc == 1)
		return (0);
	strategy = 0;
	first = 1;
	if (argv[1][0] == '-')
	{
		strategy = parse_flag(argv[1]);
		if (strategy == -1)
			return (write(2, "Error\n", 6), 1);
		first++;
	}
	if (first == argc || !valid_arguments(argc, argv, first))
		return (write(2, "Error\n", 6), 1);
	a = make_stack(argc, argv, first);
	b = NULL;
	if (!a)
		return (write(2, "Error\n", 6), 1);
	ft_order66(&a);
	if (ft_lstsize(a) > 1 && !is_sorted(a))
		run_algo(&a, &b, strategy);
	free_stack(a);
	free_stack(b);
	return (0);
}
