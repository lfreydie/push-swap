/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:03:53 by lefreydier        #+#    #+#             */
/*   Updated: 2023/02/22 17:39:16 by lfreydie         ###   ########.fr       */
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
		if (piles->mouvs)
			ft_free_mouvs(piles->mouvs);
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

void	ft_free_mouvs(t_mouvs *lst)
{
	t_mouvs	*tmp;

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
