/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvs_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:29:59 by lefreydier        #+#    #+#             */
/*   Updated: 2023/02/09 12:20:01 by lfreydie         ###   ########.fr       */
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
	piles->b->prev = NULL;
	tmp_b->next = piles->a;
	if (tmp_b->next)
		piles->a->prev = tmp_b;
	piles->a = tmp_b;
	piles->size_a++;
	piles->size_b--;
	return (1);
}

int	mv_pb(t_infos *piles)
{
	t_element	*tmp_a;

	if (!piles->a)
		return (0);
	tmp_a = piles->a;
	piles->a = tmp_a->next;
	piles->a->prev = NULL;
	tmp_a->next = piles->b;
	if (tmp_a->next)
		piles->b->prev = tmp_a;
	piles->b = tmp_a;
	piles->size_a--;
	piles->size_b++;
	return (1);
}
