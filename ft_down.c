
void lst_down(t_list **lst)
{
    t_list *tmp;
    t_lis *first;

    if (!lst || !(*lst) || !(*lst)->pile)
        return ;
    tmp = *lst;
    first = *lst;
    while (first->pile != NULL)
        first++;    
    first = tmp;
}