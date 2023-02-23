/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:03:53 by lefreydier        #+#    #+#             */
/*   Updated: 2023/02/23 18:26:20 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus.h"

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
