/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:22:02 by lfreydie          #+#    #+#             */
/*   Updated: 2023/02/09 15:53:48 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pa(t_infos *piles)
{
	int	count_first;
	int	count_last;
	int	count_last_tmp;

	count_first = ft_count_pb(piles, piles->b);
	count_last = ft_count_pb(piles, ft_lstlast(piles->b));
	count_last_tmp = count_last - count_correct(piles, ft_lstlast(piles->b));
	if (count_first > count_last_tmp)
	{
		while (count_first > 0)
		{
			if (piles->a->rank < piles->b->rank)
				ft_show(piles, mv_ra(piles), "ra");
			else
				ft_show(piles, mv_rra(piles), "rra");
			count_first--;
		}
	}
	else
	{
		ft_show(piles, mv_rrb(piles), "rrb");
		count_last--;
		while (count_last > 0)
		{
			if (piles->a->rank < piles->b->rank)
				ft_show(piles, mv_ra(piles), "ra");
			else
				ft_show(piles, mv_rra(piles), "rra");
			count_last--;
		}
	}
	ft_show(piles, mv_pa(piles), "pa");
}

int	count_correct(t_infos *piles, t_element *last)
{
	t_element	*last_a;

	last_a = ft_lstlast(piles->a);
	if (last->rank < piles->a->rank && last->rank < last_a->rank)
		return (1);
	return (0);
}
