/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:53:14 by lfreydie          #+#    #+#             */
/*   Updated: 2023/01/31 01:02:22 by lefreydier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_infos	*piles;

	if (ac < 2)
		return (0);
	else if (ac > 2)
	{
		piles = ft_init(ac - 1, av + 1);
		if (!piles)
			return (-1);
	}
	if (piles->size > 5)
		algo_gd(piles);
	else
		algo_pt(piles);
	return (0);
}
