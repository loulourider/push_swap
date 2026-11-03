/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push.h                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/03 09:34:25 by username         #+#    #+#              */
/*   Updated: 2026/11/03 12:58:17 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				index;
	int				chiffre;
	struct s_list	*pile;
}	t_list;

t_list	*add_back(t_list *head, int value);
void	print_stacks(t_list *a, t_list *b);
t_list	*print_cell(t_list *s);
void	ft_pb(t_list **a, t_list **b);
void	ft_pa(t_list **a, t_list **b);
int		ft_atoi(const char *str);
int		parsing(int argc, char **argv);
int		in_range(char *s);
t_list	*creat_stack(int *nbrs, int size);
#endif
