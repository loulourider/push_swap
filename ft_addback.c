#include "push.h"
#include <stdio.h>

void    ft_addback_a(t_list **a, int index)
{
    t_list *tmp;
    t_list *new;

    new = malloc(sizeof (t_list));
    if (!new)
        return ;
    new->index = index;
    new->pile = NULL;
    if (!*(a))
    {
        *a = new;
        return ;
    }
    tmp = *a;
    while (tmp->pile != NULL)
        tmp = tmp->pile;
    tmp->pile = new;
}

