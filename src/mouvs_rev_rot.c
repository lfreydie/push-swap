/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvs_rev_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:31:36 by lefreydier        #+#    #+#             */
/*   Updated: 2023/02/07 12:05:28 by lfreydie         ###   ########.fr       */
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
	piles->a->prev = tmp;
	tmp->next = piles->a;
	tmp->prev = NULL;
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
	piles->b->prev = tmp;
	tmp->next = piles->b;
	tmp->prev = NULL;
	piles->b = tmp;
	return (1);
}

int	mv_rrr(t_infos *piles)
{
	mv_rra(piles);
	mv_rrb(piles);
	return (1);
}
