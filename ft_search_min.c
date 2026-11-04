/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_serch_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallaire <lallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 13:14:33 by username          #+#    #+#             */
/*   Updated: 2026/11/04 13:16:24 by lallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_list	*find_min(t_list *lst)
{
	t_list	*min;

	if (lst == NULL)
		return (NULL);
	min = lst;
	while (lst != NULL)
	{
		if (lst->index < min->index)
			min = lst;
		lst = lst->pile;
	}
	return (min);
}
