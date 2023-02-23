/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:35:36 by lfreydie          #+#    #+#             */
/*   Updated: 2023/02/23 17:53:49 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus.h"

t_element	*ft_lstnew(int nombre, int *tab, int len)
{
	t_element	*new;
	int			i;

	i = 0;
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->nombre = nombre;
	while (i < len)
	{
		if (tab[i] == nombre)
			new->rank = i + 1;
		i++;
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_element	*ft_lstadd_back(t_element *lst, int nombre, int *tab, int len)
{
	t_element	*tmp;
	t_element	*new;

	new = NULL;
	if (lst)
	{
		tmp = ft_lstlast(lst);
		new = ft_lstnew(nombre, tab, len);
		if (!new || !tmp)
			return (free(tmp), free(new), NULL);
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
