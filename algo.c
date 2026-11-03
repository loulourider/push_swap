
void	*ft_order66(t_list **a)
{
	int	i;
	int	j;
	int count;
	
	
	i = 0;
	j = 0;
	while (*a[i])
	{
		count = 0;
		j = 0;
		while (*a[j])
		{
			if (*a[j] < *a[i])
				count = count + 1;
			j ++;
		}
		*a[i] = count;
		i++;
	}
}	

