/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morganeberthod <morganeberthod@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:53:14 by lfreydie          #+#    #+#             */
/*   Updated: 2023/02/19 09:07:17 by morganebert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_infos	*piles;

	piles = NULL;
	if (ac <= 2)
		return (0);
	else
	{
		piles = init(ac - 1, av + 1);
		if (!piles)
			return (-1);
	}
	algo(piles);
	return (0);
}
