/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvs_rev_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:31:36 by lefreydier        #+#    #+#             */
/*   Updated: 2023/01/31 00:45:32 by lefreydier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	mv_rra(t_infos *piles)
{
	t_element	*tmp;
	t_element	*last;

	tmp = ft_lstlast(piles->a);
	last = tmp->prev;
	last->next = NULL;
	tmp->next = piles->a;
	piles->a = tmp;
	return (1);
}

int	mv_rrb(t_infos *piles)
{
	t_element	*tmp;
	t_element	*last;

	tmp = ft_lstlast(piles->b);
	last = tmp->prev;
	last->next = NULL;
	tmp->next = piles->b;
	piles->b = tmp;
	return (1);
}

int	mv_rrr(t_infos *piles)
{
	mv_rra(piles);
	mv_rrb(piles);
	return (1);
}
