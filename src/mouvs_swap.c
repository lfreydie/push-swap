/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvs_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:55:16 by lefreydier        #+#    #+#             */
/*   Updated: 2023/02/07 12:02:35 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	mv_sa(t_infos *piles)
{
	t_element	*tmp_a_f;
	t_element	*tmp_a_s;

	if (!piles->a || !piles->a->next)
		return (0);
	tmp_a_f = piles->a;
	tmp_a_s = piles->a->next;
	tmp_a_f->next = tmp_a_s->next;
	tmp_a_f->prev = tmp_a_s;
	tmp_a_s->next = tmp_a_f;
	tmp_a_s->prev = NULL;
	piles->a = tmp_a_s;
	return (1);
}

int	mv_sb(t_infos *piles)
{
	t_element	*tmp_b_f;
	t_element	*tmp_b_s;

	if (!piles->b || !piles->b->next)
		return (0);
	tmp_b_f = piles->b;
	tmp_b_s = piles->b->next;
	tmp_b_f->next = tmp_b_s->next;
	tmp_b_f->prev = tmp_b_s;
	tmp_b_s->next = tmp_b_f;
	tmp_b_s->prev = NULL;
	piles->b = tmp_b_s;
	return (1);
}

int	mv_ss(t_infos *piles)
{
	if (!piles->a || !piles->a->next || !piles->b || !piles->b->next)
		return (0);
	mv_sa(piles);
	mv_sb(piles);
	return (1);
}
