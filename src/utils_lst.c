/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:35:36 by lfreydie          #+#    #+#             */
/*   Updated: 2023/01/31 00:39:57 by lefreydier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_element	*ft_lstnew(int nombre)
{
	t_element	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->nombre = nombre;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_element	*ft_lstadd_back(t_element *lst, t_element *new, int nombre)
{
	t_element	*tmp;
	t_element	*last;

	if (lst)
	{
		tmp = ft_lstlast(lst);
		last = ft_lstnew(nombre);
		if (!tmp->next)
			return (NULL);
		tmp->next = last;
		last->prev = tmp;
	}
	return (last);
}

t_element	*ft_lstlast(t_element *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
