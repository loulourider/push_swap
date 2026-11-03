/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/03 12:22:35 by username         #+#    #+#              */
/*   Updated: 2026/11/03 12:59:35 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		*nbrs;
	int		i;
	int		j;

	if (parsing(argc, argv) == 0)
		return (0);
	b = NULL;
	if (argc < 2)
		return (0);
	nbrs = malloc(sizeof(int) * (argc - 1));
	if (!nbrs)
		return (1);
	i = 0;
	while (i < argc - 1)
	{
		nbrs[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	a = creat_stack(nbrs, argc - 1);
	print_stacks(a, b);
	ft_pb(&a, &b);
	print_stacks(a, b);
	return (0);
}
