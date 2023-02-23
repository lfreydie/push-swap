/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:55:50 by lefreydier        #+#    #+#             */
/*   Updated: 2023/02/23 17:49:55 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus.h"

int	correct(t_element *lst)
{
	if (!lst)
		return (0);
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

int	ft_check_piles(t_infos *piles)
{
	if (piles->b)
		return (write(1, "KO\n", 3), 0);
	if (!correct(piles->a))
		return (write(1, "KO\n", 3), 0);
	return (write(1, "OK\n", 3), 1);
}
