/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morganeberthod <morganeberthod@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:21:01 by lfreydie          #+#    #+#             */
/*   Updated: 2023/02/10 11:45:44 by morganebert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_pb(t_infos *piles, t_element *lst, int limit)
{
	int	count_ra;
	int	count_rra;

	count_ra = ft_find_count_ra(lst, limit);
	count_rra = ft_find_count_rra(lst, limit);
	if (count_ra <= count_rra)
	{
		while (count_ra > 0)
		{
			ft_show(piles, mv_ra(piles), "ra");
			count_ra--;
		}
		ft_show(piles, mv_pb(piles), "pb");
	}
	else if (count_ra > count_rra)
	{
		while (count_rra-- > 0)
			ft_show(piles, mv_rra(piles), "rra");
		ft_show(piles, mv_pb(piles), "pb");
	}
	return (1);
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
