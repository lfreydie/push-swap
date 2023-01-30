/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvs_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:30:35 by lefreydier        #+#    #+#             */
/*   Updated: 2023/01/31 00:44:45 by lefreydier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	mv_ra(t_infos *piles)
{
	t_element	*tmp;
	t_element	*last;

	tmp = piles->a;
	piles->a = tmp->next;
	tmp->next = NULL;
	last = ft_lstlast(piles->a);
	last->next = tmp;
	return (1);
}

int	mv_rb(t_infos *piles)
{
	t_element	*tmp;
	t_element	*last;

	tmp = piles->b;
	piles->b = tmp->next;
	tmp->next = NULL;
	last = ft_lstlast(piles->b);
	last->next = tmp;
	return (1);
}

int	mv_rr(t_infos *piles)
{
	mv_ra(piles);
	mv_rb(piles);
	return (1);
}
