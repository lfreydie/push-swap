/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvs_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:55:16 by lefreydier        #+#    #+#             */
/*   Updated: 2023/02/24 12:22:11 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	mv_sa(t_infos *piles)
{
	t_element	*tmp_a_1;
	t_element	*tmp_a_2;
	t_element	*tmp_a_3;

	if (!piles->a || !piles->a->next)
		return (0);
	tmp_a_1 = piles->a;
	tmp_a_2 = piles->a->next;
	tmp_a_3 = tmp_a_2->next;
	tmp_a_1->next = tmp_a_3;
	tmp_a_1->prev = tmp_a_2;
	tmp_a_2->next = tmp_a_1;
	tmp_a_2->prev = NULL;
	tmp_a_3->prev = tmp_a_1;
	piles->a = tmp_a_2;
	return (1);
}

int	mv_sb(t_infos *piles)
{
	t_element	*tmp_b_1;
	t_element	*tmp_b_2;
	t_element	*tmp_b_3;

	if (!piles->b || !piles->b->next)
		return (0);
	tmp_b_1 = piles->b;
	tmp_b_2 = piles->b->next;
	tmp_b_3 = tmp_b_2->next;
	tmp_b_1->next = tmp_b_2->next;
	tmp_b_1->prev = tmp_b_2;
	tmp_b_2->next = tmp_b_1;
	tmp_b_2->prev = NULL;
	tmp_b_3->prev = tmp_b_1;
	piles->b = tmp_b_2;
	return (1);
}

int	mv_ss(t_infos *piles)
{
	if (piles->a && piles->a->next)
		mv_sa(piles);
	if (piles->b && piles->b->next)
		mv_sb(piles);
	return (1);
}
