/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:35:36 by lfreydie          #+#    #+#             */
/*   Updated: 2023/02/16 13:13:59 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_element	*ft_lstnew(int nombre, int *tab)
{
	t_element	*new;
	int			i;

	i = 0;
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->nombre = nombre;
	while (tab[i])
	{
		if (tab[i] == nombre)
			new->rank = i + 1;
		i++;
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_element	*ft_lstadd_back(t_element *lst, int nombre, int *tab)
{
	t_element	*tmp;
	t_element	*new;

	if (lst)
	{
		tmp = ft_lstlast(lst);
		new = ft_lstnew(nombre, tab);
		if (!new)
			return (NULL);
		tmp->next = new;
		new->prev = tmp;
	}
	return (new);
}

t_element	*ft_lstlast(t_element *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
