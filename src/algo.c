/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:54:23 by lefreydier        #+#    #+#             */
/*   Updated: 2023/02/22 15:15:35 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo(t_infos *piles)
{
	if (piles->size_a <= 3)
		algo_pt(piles);
	else if (piles->size_a > 3 && !correct(piles->a))
	{
		pb_pre_tri(piles);
		algo_pt(piles);
		ft_pa(piles);
	}
	while (piles->a->rank != 1)
		stock(piles, mv_rra(piles), "rra");
	ft_show_mouvs(piles);
	ft_free_piles(piles);
}

void	algo_pt(t_infos *piles)
{
	t_element	*last;

	last = NULL;
	while (!correct(piles->a))
	{
		last = ft_lstlast(piles->a);
		if (piles->size_a == 2)
			stock(piles, mv_sa(piles), "sa");
		else if (piles->a->nombre > piles->a->next->nombre)
		{
			if ((piles->a->next->nombre < last->nombre) \
			&& (piles->a->nombre > last->nombre))
				stock(piles, mv_ra(piles), "ra");
			else
				stock(piles, mv_sa(piles), "sa");
		}
		else
		{
			if (piles->a->nombre > last->nombre)
				stock(piles, mv_rra(piles), "rra");
			else
				stock(piles, mv_ra(piles), "ra");
		}
	}
}

void	pb_pre_tri(t_infos *piles)
{
	int	chunk;
	int	reste;
	int	size_a;

	chunk = 0;
	reste = 0;
	while (piles->size_a != 3)
	{
		size_a = piles->size_a;
		chunk = piles->size_a / 3;
		reste = piles->size_a % 3;
		if (chunk < 3)
		{
			ft_push_b(piles, piles->a, piles->size - 3);
			piles->b->range = piles->size;
		}
		else
		{
			while (piles->size_a > (size_a - (2 * chunk)))
			{
				ft_push_b(piles, piles->a, piles->size - (chunk + reste));
				organize_b(piles, chunk, reste);
			}
		}
	}
}
