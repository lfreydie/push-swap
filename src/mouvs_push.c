/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvs_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:29:59 by lefreydier        #+#    #+#             */
/*   Updated: 2023/01/30 22:40:11 by lefreydier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	mv_pa(t_infos *piles)
{
	t_element	*tmp_b;

	if (!piles->b)
		return (0);
	tmp_b = piles->b;
	piles->b = tmp_b->next;
	tmp_b->next = piles->a;
	piles->a = tmp_b;
	return (1);
}

int	mv_pb(t_infos *piles)
{
	t_element	*tmp_a;

	if (!piles->a)
		return (0);
	tmp_a = piles->a;
	piles->a = tmp_a->next;
	tmp_a->next = piles->b;
	piles->b = tmp_a;
	return (1);
}
