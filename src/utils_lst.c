/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morganeberthod <morganeberthod@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:35:36 by lfreydie          #+#    #+#             */
/*   Updated: 2023/02/19 09:37:40 by morganebert      ###   ########.fr       */
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
	new->range = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_element	*ft_lstadd_back(t_element *lst, int nombre, int *tab)
{
	t_element	*tmp;
	t_element	*new;

	new = NULL;
	if (lst)
	{
		printf("On veut last de piles->a pour init donnees : \n");
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
	{
		printf("elem : %d , ", lst->nombre);
		lst = lst->next;
	}
	printf("elem : %d\n", lst->nombre);
	return (lst);
}

int	find_range_up(t_element *lst)
{
	int	range_up;

	range_up = 0;
	while (lst)
	{
		if (range_up < lst->range)
			range_up = lst->range;
		lst = lst->next;
	}
	return (range_up);
}
