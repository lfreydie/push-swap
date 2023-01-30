/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:03:53 by lefreydier        #+#    #+#             */
/*   Updated: 2023/01/30 21:40:23 by lefreydier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_piles(t_infos *piles)
{
	if (!piles)
		return ;
	else
	{
		if (piles->a)
			ft_free_element(piles->a);
		if (piles->b)
			ft_free_element(piles->b);
		if (piles->tab)
			free(piles->tab);
		return (free(piles));
	}
}

void	ft_free_element(t_element *lst)
{
	t_element	*tmp;

	if (!lst)
		return ;
	if (lst)
	{
		while (lst)
		{
			tmp = lst->next;
			free(lst);
			lst = tmp;
		}
	}
}
