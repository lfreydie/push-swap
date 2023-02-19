/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvs_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morganeberthod <morganeberthod@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:30:35 by lefreydier        #+#    #+#             */
/*   Updated: 2023/02/19 09:32:12 by morganebert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	mv_ra(t_infos *piles)
{
	t_element	*tmp;
	t_element	*last;

	tmp = piles->a;
	piles->a = tmp->next;
	piles->a->prev = NULL;
	tmp->next = NULL;
	printf("on veut last de piles->a | mv_ra : \n");
	last = ft_lstlast(piles->a);
	last->next = tmp;
	tmp->prev = last;
	return (1);
}

int	mv_rb(t_infos *piles)
{
	t_element	*tmp;
	t_element	*last;

	tmp = piles->b;
	piles->b = tmp->next;
	piles->b->prev = NULL;
	tmp->next = NULL;
	printf("on veut last de piles->b | mv_rb : \n");
	last = ft_lstlast(piles->b);
	last->next = tmp;
	tmp->prev = last;
	return (1);
}

int	mv_rr(t_infos *piles)
{
	mv_ra(piles);
	mv_rb(piles);
	return (1);
}
