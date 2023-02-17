/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:22:02 by lfreydie          #+#    #+#             */
/*   Updated: 2023/02/17 14:25:49 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pa(t_infos *piles)
{
	t_element	*elem;

	elem = NULL;
	while (piles->b)
	{
		elem = ft_find_elem(piles);
		ft_mv_pa(piles, elem, ft_count_a(piles, elem), ft_count_b(piles, elem));
		stock(piles, mv_pa(piles), "pa");
	}
	while (piles->a->rank != 1)
		stock(piles, mv_rra(piles), "rra");
}

t_element	*find_elem(t_infos *piles)
{
	t_element	*lst;
	t_element	*elem;
	uint		range_up;
	int			minmv;
	int			mv;

	range_up = find_range_up(piles->b);
	lst = piles->b;
	while (lst)
	{
		if (lst->range == range_up)
		{
			minmv = count_mv(piles, ft_count_a(piles, elem), \
					ft_count_b(piles, elem));
			if (minmv < mv)
			{
				mv = minmv;
				elem = lst;
			}
		}
		lst = lst->next;
	}
	return (elem);
}

int	count_mv(t_infos *piles, int mv_a, int mv_b)
{
	if ((mv_a > (piles->size_a / 2)) && (mv_b > (piles->size_b / 2)))
	{
		mv_a = piles_->size_a - mv_a;
		mv_b = piles_->size_b - mv_b;
	}
	if ((mv_a <= (piles->size_a / 2)) && (mv_b <= (piles->size_b / 2)))
	{
		if (mv_a > mv_b)
			return (mv_a);
		else
			return (mv_b);
	}
	else if ((mv_a > (piles->size_a / 2)))
		mv_a = piles_->size_a - mv_a;
	else if ((mv_b > (piles->size_b / 2)))
		mv_b = piles_->size_b - mv_b;
	return (mv_a + mv_b);
}

void	ft_mv_pa(t_infos *piles, t_element *elem, int mv_a, int mv_b)
{
	while ((mv_a > 0 && mv_a <= piles->size_a) || \
		(mv_b > 0 && mv_b <= piles->size_b))
	{
		if (mv_a > (piles->size_a / 2 + piles->size_a % 2) && \
			piles->size_a <= mv_a)
			mv_a += stock(piles, mv_rra(piles), "rra");
		else if (mv_a < piles->size_a / 2 + piles->size_a % 2)
			mv_a -= stock(piles, mv_ra(piles), "ra");
		if (mv_b > (piles->size_b / 2 + piles->size_b % 2) && \
			piles->size_b <= mv_b)
			mv_b += stock(piles, mv_rrb(piles), "rrb");
		else if (mv_b < piles->size_b / 2 + piles->size_b % 2)
			mv_b -= stock(piles, mv_rb(piles), "rb");
	}
}