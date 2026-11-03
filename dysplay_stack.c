/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   dysplay_stack.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/03 09:36:13 by username         #+#    #+#              */
/*   Updated: 2026/11/03 10:15:44 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include "ft_printf.h"

static t_list	*print_cell(t_list *s)
{
	if (s)
	{
		ft_printf("%d", s->chiffre);
		ft_printf("\t");
		return (s->pile);
	}
	ft_printf("\t");
	return (NULL);
}

void	print_stacks(t_list *a, t_list *b)
{
	while (a || b)
	{
		a = print_cell(a);
		b = print_cell(b);
		ft_printf("\n");
	}
	ft_printf("_\t_\n");
	ft_printf("a\tb\n");
}

// static t_list	*add_back(t_list *head, int value)
// {
// 	t_list	*new;
// 	t_list	*tmp;

// 	new = malloc(sizeof(t_list));
// 	if (!new)
// 		return (head);
// 	new->index = 0;
// 	new->chiffre = value;
// 	new->pile = NULL;
// 	if (!head)
// 		return (new);
// 	tmp = head;
// 	while (tmp->pile)
// 		tmp = tmp->pile;
// 	tmp->pile = new;
// 	return (head);
// }

// static void	free_stack(t_list *s)
// {
// 	t_list	*tmp;

// 	while (s)
// 	{
// 		tmp = s->pile;
// 		free(s);
// 		s = tmp;
// 	}
// }

// int	main(void)
// {
// 	t_list	*a;
// 	t_list	*b;

// 	a = NULL;
// 	b = NULL;
// 	a = add_back(a, 2);
// 	a = add_back(a, 14);
// 	a = add_back(a, 396);
// 	a = add_back(a, 63453646);
// 	a = add_back(a, 5);
// 	a = add_back(a, 8);
// 	printf("--- a: 6 elements, b: vide ---\n");
// 	print_stacks(a, b);
// 	b = add_back(b, 42);
// 	b = add_back(b, -2147483648);
// 	b = add_back(b, 8);
// 	b = add_back(b, 4);
// 	b = add_back(b, 95456);
// 	printf("\n--- a: 6 elements, b: 2 elements ---\n");
// 	print_stacks(a, b);
// 	free_stack(a);
// 	a = NULL;
// 	printf("\n--- a: vide, b: 2 elements ---\n");
// 	print_stacks(a, b);
// 	printf("\n--- les deux vides ---\n");
// 	print_stacks(NULL, NULL);
// 	free_stack(b);
// 	return (0);
// }
