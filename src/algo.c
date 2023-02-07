/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:54:23 by lefreydier        #+#    #+#             */
/*   Updated: 2023/02/07 14:57:23 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo(t_infos *piles)
{
	if (piles->size_a <= 3)
		algo_pt(piles);
	else
		algo_gd(piles);
}

void	algo_pt(t_infos *piles)
{
	t_element	*last;

	last = NULL;
	while (is_correct(piles->a) == -1)
	{
		last = ft_lstlast(piles->a);
		if (piles->size_a < 3)
			ft_show(mv_pa(piles), "pa");
		else if (piles->a->nombre > piles->a->next->nombre)
		{
			if ((piles->a->next->nombre < last->nombre) \
			&& (piles->a->nombre > last->nombre))
				ft_show(mv_ra(piles), "ra");
			else
				ft_show(mv_sa(piles), "sa");
		}
		else
		{
			if (piles->a->nombre > last->nombre)
				ft_show(mv_rra(piles), "rra");
			else
				ft_show(mv_ra(piles), "ra");
		}
	}
}

void	algo_gd(t_infos *piles)
{
	int	i;

	i = 0;
	while (i++ < (piles->size / 2))
		mv_pb(piles);
}
