/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_mv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:00:10 by lfreydie          #+#    #+#             */
/*   Updated: 2023/02/17 12:51:30 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_framed(int obj, int first, int last)
{
	if ((first > obj) && ((first < last) || ((first > last) && (last < obj))))
		return (1);
	return (0);
}

int	test_mv_ra(t_element *first, t_element *last)
{
	last = first;
	first = first->next;
	return (1);
}

int	count_ra(t_element *first, t_element *last, t_element *obj)
{
	int	count;

	count = 0;
	while (!is_framed(obj->rank, first->rank, last->rank))
	{
		if ((first->rank > obj->rank) \
		&& (last->rank > obj->rank) && (first->rank > last->rank))
			count += test_mv_ra(first, last);
		else if (first->rank < obj->rank)
		{
			if (last->rank < obj->rank)
				count += test_mv_ra(first, last);
			else if (last->rank > obj->rank)
				count += test_mv_ra(first, last);
		}
		if (!first)
			return (-1);
	}
	return (count);
}

int	ft_count_a(t_infos *piles, t_element *elem)
{
	int			count;
	t_element	*first_a;
	t_element	*last_a;

	first_a = piles->a;
	last_a = ft_lstlast(piles->a);
	count = count_ra(first_a, last_a, elem);
	return (count);
}

int	ft_count_b(t_infos *piles, t_element *elem)
{
	int			count;
	t_element	*lst;

	count = 0;
	lst = piles->b;
	while (lst)
	{
		if (lst == elem)
			return (count);
		count++;
		lst = lst->next;
	}
	return (-1);
}
