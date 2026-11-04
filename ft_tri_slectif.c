#include "push.h"

static int direction(t_list *lst)
{
	int 	count;
	t_list	*pos;
	int		size;
	int		min;

	min = find_min(lst);
	size = lst_size(lst);
	count = 0;
	pos = *lst;
	while (pos != min)
	{
		pos = pos->pile;
		count++;
	} 

	if (count <= size - count)
		return (1);
	else 
		return (0);
}

void tri_selectif(t_list **a, t_list **b)
{
	t_list	*pos;
	int		move;

	while (*a != NULL)
	{
		pos  = find_min(*a);
		move = direction(*a);
		if (move > 0)
		{
			while (pos != *a)
				lst_up(a, "a");

		}
		else
		{
			while (pos != *a)
				lst_down(a, "a");
		}
		ft_pb(a, b);
	}
	while (*b != NULL)
		ft_pa(a, b);
}

