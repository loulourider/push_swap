static void push(t_list **src, t_list **dst)
{
    t_list *tmp;

    if (!(*src))
        return (0);
    tmp = *src;
    *src = *src->next;
    tmp->next = (*dest);
    (*dest) = tmp;
}
void  *ft_pb(t_list **a, t_list **b)
{
    push(a, b);
    ft_putstr("pb\n, 1")
}

void  *ft_pa(t_list **a, t_list **b)
{
    push(b, a);
    ft_putstr("pa\n, 1");
}