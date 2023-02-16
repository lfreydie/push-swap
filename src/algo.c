/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:54:23 by lefreydier        #+#    #+#             */
/*   Updated: 2023/02/16 15:08:44 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo(t_infos *piles)
{
	if (piles->size_a <= 3)
		algo_pt(piles);
	else
	{
		algo_gd(piles);
		algo_rrange(piles);
	}
	ft_show_mouvs(piles);
}

void	algo_pt(t_infos *piles)
{
	t_element	*last;

	last = NULL;
	while (!correct(piles->a))
	{
		last = ft_lstlast(piles->a);
		if (piles->size_a == 2)
			ft_show(piles, mv_sa(piles), "sa");
		else if (piles->a->nombre > piles->a->next->nombre)
		{
			if ((piles->a->next->nombre < last->nombre) \
			&& (piles->a->nombre > last->nombre))
				ft_show(piles, mv_ra(piles), "ra");
			else
				ft_show(piles, mv_sa(piles), "sa");
		}
		else
		{
			if (piles->a->nombre > last->nombre)
				ft_show(piles, mv_rra(piles), "rra");
			else
				ft_show(piles, mv_ra(piles), "ra");
		}
	}
}

void	algo_gd(t_infos *piles)
{
	int	div;
	int	mod;
	int	n;

	div = 0;
	mod = 0;
	n = 0;
	while (piles->size_a != 3)
	{
		n = piles->size_a;
		div = piles->size_a / 3;
		mod = piles->size_a % 3;
		if (div < 3)
			ft_pb(piles, piles->a, piles->size - 3);
		else
		{
			while (piles->size_a > (n - (2 * div)))
			{
				ft_pb(piles, piles->a, piles->size - (div + mod));
				if (piles->b->rank > piles->size - (mod + (2 * div)))
					ft_show(piles, mv_rb(piles), "rb");
			}
		}
	}
	algo_pt(piles);
}

void	algo_rrange(t_infos *piles)
{
	while (piles->size_b)
	{
		
	}
}
