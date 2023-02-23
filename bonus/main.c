/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:53:14 by lfreydie          #+#    #+#             */
/*   Updated: 2023/02/23 18:31:08 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus.h"

int	main(int ac, char **av)
{
	t_infos	*piles;

	piles = NULL;
	if (ac <= 2)
	{
		if (ac == 2 && !ft_isnbr(av[1]))
			return (write(2, "Error\n", 6), 1);
		return (0);
	}
	else
	{
		piles = init(ac - 1, av + 1);
		if (!piles)
			return (1);
	}
	if (!ft_exec(piles))
		return (ft_free_piles(piles), write(2, "Error\n", 6), 1);
	if (!ft_check_piles(piles))
		return (ft_free_piles(piles), 1);
	ft_free_piles(piles);
	return (0);
}
