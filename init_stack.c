/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallaire <lallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:01:16 by username          #+#    #+#             */
/*   Updated: 2026/11/04 12:02:04 by lallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_list	*init_stack(int argc, char **argv)
{
	t_list	*a;
	int		*nbrs;
	int		i;

	if (parsing(argc, argv) == 0)
		return (NULL);
	nbrs = malloc(sizeof(int) * (argc - 1));
	if (!nbrs)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		nbrs[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	a = creat_stack(nbrs, argc - 1);
	free(nbrs);
	if (a)
		ft_order66(&a);
	return (a);
}

void	free_stack(t_list *s)
{
	t_list	*tmp;

	while (s)
	{
		tmp = s->pile;
		free(s);
		s = tmp;
	}
}
