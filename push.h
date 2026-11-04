/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallaire <lallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 09:34:25 by username          #+#    #+#             */
/*   Updated: 2026/11/04 13:21:17 by lallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# define ALGO_SIMPLE 1
# define ALGO_MEDIUM 2
# define ALGO_COMPLEX 3

typedef struct s_list
{
	int				index;
	int				chiffre;
	struct s_list	*pile;
}	t_list;
int		compute_disorder(t_list *a);
int		is_sorted(t_list *a);
void	simple_sort(t_list **a, t_list **b);
int		choose_algo(int strategy, int disorder);
t_list	*add_back(t_list *head, int value);
void	print_stacks(t_list *a, t_list *b);
t_list	*print_cell(t_list *s);
int		ft_pb(t_list **a, t_list **b);
int		ft_pa(t_list **a, t_list **b);
int		ft_atoi(const char *str);
int		parsing(int argc, char **argv);
int		in_range(char *s);
t_list	*creat_stack(int *nbrs, int size);
int		lst_up(t_list **lst, char c);
int		lst_down(t_list **lst, char c);
void	ft_order66(t_list **a);
int		radix_sort(t_list **a, t_list **b);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
t_list	*init_stack(int argc, char **argv);
void	free_stack(t_list *s);
void	chunk_sort(t_list **a, t_list **b);
void	push_chunks(t_list **a, t_list **b, int chunk_size);
void	push_max_to_a(t_list **a, t_list **b);
int		get_max_pos(t_list *b);
void	run_algo(t_list **a, t_list **b, int strategy);
int		ft_strcmp(char *s1, char *s2);
t_list	*find_min(t_list *lst);
void	tri_selectif(t_list **a, t_list **b);
#endif
