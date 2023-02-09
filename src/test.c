/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:55:50 by lefreydier        #+#    #+#             */
/*   Updated: 2023/02/09 15:21:30 by lfreydie         ###   ########.fr       */
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
