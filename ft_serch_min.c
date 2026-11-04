
t_list *find_min(t_list *lst)
{
	t_list *min;
	
	if (lst == NULL)
		return (NULL);
	min = *lst;
	while (lst != NULL)
	{
		if (lst->index < min_index->index)
			min = lst;
		lst = lst->pile;
	}
	return (min); 
}
