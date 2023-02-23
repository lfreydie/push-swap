/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvs_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:30:35 by lefreydier        #+#    #+#             */
/*   Updated: 2023/02/23 18:04:49 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus.h"

int	mv_ra(t_infos *piles)
{
	t_element	*tmp;
	t_element	*last;

	if (!piles->a || !piles->a->next)
		return (0);
	tmp = piles->a;
	piles->a = tmp->next;
	piles->a->prev = NULL;
	tmp->next = NULL;
	last = ft_lstlast(piles->a);
	last->next = tmp;
	tmp->prev = last;
	return (1);
}

int	mv_rb(t_infos *piles)
{
	t_element	*tmp;
	t_element	*last;

	if (!piles->b || !piles->b->next)
		return (0);
	tmp = piles->b;
	piles->b = tmp->next;
	piles->b->prev = NULL;
	tmp->next = NULL;
	last = ft_lstlast(piles->b);
	last->next = tmp;
	tmp->prev = last;
	return (1);
}

int	mv_rr(t_infos *piles)
{
	if (piles->a && piles->a->next)
		mv_ra(piles);
	if (piles->b && piles->b->next)
		mv_rb(piles);
	return (1);
}
