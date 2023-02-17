/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:54:23 by lefreydier        #+#    #+#             */
/*   Updated: 2023/02/17 14:26:20 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo(t_infos *piles)
{
	if (piles->size_a <= 3)
		algo_pt(piles);
	else
	{
		pb_pre_tri(piles);
		ft_pa(piles);
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

	chunk = 0;
	reste = 0;
	while (piles->size_a != 3)
	{
		chunk = piles->size_a / 3;
		reste = piles->size_a % 3;
		if (chunk < 3)
			ft_push_b(piles, piles->a, piles->size - 3);
		else
		{
			while (piles->size_a > (piles->size_a - (2 * chunk)))
			{
				ft_push_b(piles, piles->a, piles->size - (chunk + reste));
				organize_b(piles, chunk, reste);
			}
		}
	}
	algo_pt(piles);
}
