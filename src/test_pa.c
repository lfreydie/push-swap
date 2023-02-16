/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:22:02 by lfreydie          #+#    #+#             */
/*   Updated: 2023/02/16 15:11:28 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pa(t_infos *piles)
{
	int	count_first;
	int	count_last;
	int	mv;

	count_first = ft_count_pa(piles, piles->b);
	count_last = ft_count_pa(piles, ft_lstlast(piles->b)) + 1;
	if (count_first < count_last)
	{
		count = count_first;
		mv = ft_mv(piles, piles->b);
	}
	else
	{
		count = count_last - 1;
		ft_show(piles, mv_rrb(piles), "rrb");
		mv = ft_mv(piles, ft_lstlast(piles->b));
	}
	while (count--)
	{
		if (mv == 1)
			ft_show(piles, mv_ra(piles), "ra");
		else
			ft_show(piles, mv_rra(piles), "rra");
	}
	ft_show(piles, mv_pa(piles), "pa");
}

int	ft_count_pa(t_infos *piles, t_element *obj)
{
	int			count_ra;
	int			count_rra;
	t_element	*first_a;
	t_element	*last_a;

	first_a = piles->a;
	last_a = ft_lstlast(piles->a);
	count_ra = test_ra(first_a, last_a);
	count_rra = test_rra(first_a, last_a);
	if (count_ra < count_rra)
		return (count_ra);
	else
		return (count_rra);
}

int	ft_mv(t_infos *piles, t_element *obj)
{
	int			count_ra;
	int			count_rra;
	t_element	*first_a;
	t_element	*last_a;

	first_a = piles->a;
	last_a = ft_lstlast(piles->a);
	count_ra = test_ra(first_a, last_a);
	count_rra = test_rra(first_a, last_a);
	if (count_ra < count_rra)
		return (1);
	else
		return (2);
}
