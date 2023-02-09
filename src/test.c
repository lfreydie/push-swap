/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:55:50 by lefreydier        #+#    #+#             */
/*   Updated: 2023/02/09 12:19:14 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	correct(t_element *lst)
{
	while (lst->next)
	{
		if (lst->nombre > lst->next->nombre)
			return (0);
		else
			lst = lst->next;
	}
	return (1);
}

int	parse(char **av, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (ft_isnbr(av[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_pb(t_infos *piles, t_element *lst, int limit)
{
	int	count_ra;
	int	count_rra;

	count_ra = ft_find_count_ra(lst, limit);
	count_rra = ft_find_count_rra(lst, limit);
	// if ((count_ra >= (piles->size_a / 2)) && (count_rra > (piles->size_a / 2)))
	// 	return ;
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
		if (lst->nombre <= limit)
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
		if (lst->nombre <= limit)
			return (count);
		lst = lst->prev;
		count++;
	}
	return (count);
}
