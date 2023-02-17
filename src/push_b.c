/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:21:01 by lfreydie          #+#    #+#             */
/*   Updated: 2023/02/17 11:04:28 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_b(t_infos *piles, t_element *lst, int limit)
{
	int	count_ra;
	int	count_rra;

	count_ra = ft_find_count_ra(lst, limit);
	count_rra = ft_find_count_rra(lst, limit);
	if (count_ra <= count_rra)
	{
		while (count_ra--)
			stock(piles, mv_ra(piles), "ra");
		stock(piles, mv_pb(piles), "pb");
	}
	else if (count_ra > count_rra)
	{
		while (count_rra--)
			stock(piles, mv_rra(piles), "rra");
		stock(piles, mv_pb(piles), "pb");
	}
}

void	organize_b(t_infos *piles, int chunk, int reste)
{
	int	median;
	int	limit;

	median = piles->size - (reste + (2 * chunk));
	limit = piles->size - (reste + chunk);
	if (piles->b->rank <= median)
	{
		piles->b->range = median;
		stock(piles, mv_rb(piles), "rb");
	}
	else
		piles->b->range = limit;
}

int	ft_find_count_ra(t_element	*lst, int limit)
{
	int	count;

	count = 0;
	while (lst)
	{
		if (lst->rank <= limit)
			return (count);
		lst = lst->next;
		count++;
	}
	return (count);
}

int	ft_find_count_rra(t_element	*lst, int limit)
{
	int	count;

	count = 1;
	lst = ft_lstlast(lst);
	while (lst)
	{
		if (lst->rank <= limit)
			return (count);
		lst = lst->prev;
		count++;
	}
	return (count);
}
