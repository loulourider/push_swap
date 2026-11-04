
t_list  *find_max(t_list *lst)
{
    t_list *max;

    max = lst;
    while (lst != NULL)
    {
        if (lst->index > max->index)
            max = lst;
        lst = lst->pile;
    }
    return (max);
}

t_list  *find_target_in_b(t_list **lst, int value)
{
    t_list *tamp;
    t_list *pos;
	
    tamp = NULL;
    pos = *lst;
    while (pos != NULL)
    {
        if (pos->index < value && (tamp == NULL || pos->index > tamp->index))
            tamp = pos;
        pos = pos->pile;
    }
    if (tamp == NULL)
        tamp = find_max(*lst);
    return (tamp);
}




void ft_turkish(t_list **a, t_list **b)
{
	t_list	*search;
	int count = ft_count_list(**a);
	if (count > 3){
		ft_pb(**a, **b);
		ft_pb(**a, **b);
	}
	count = ft_count_list(**a);
	while (count > 3)
	{
		search->index = (*a)->index;
		search = *b;
		while (b->pile != NULL)
	}

}
