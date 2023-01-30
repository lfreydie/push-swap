/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:35:36 by lfreydie          #+#    #+#             */
/*   Updated: 2023/01/30 15:42:37 by lefreydier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lstadd_back(t_element **lst, t_element *new)
{
	t_element	*tmp;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			tmp = ft_lstlast(*(lst));
			tmp->next = new;
		}
	}
}

t_element	*ft_lstlast(t_element *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_element	*ft_lstnew(void *content)
{
	t_element	*new;

	new = malloc(sizeof(t_element));
	if (!new)
		return (NULL);
	new->nombre = content;
	new->next = NULL;
	return (new);
}
