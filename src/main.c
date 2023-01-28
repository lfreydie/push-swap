/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:53:14 by lfreydie          #+#    #+#             */
/*   Updated: 2023/01/28 15:30:19 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_infos	*piles;

	if (ac < 2)
		return (0);
	else if (ac > 2)
		piles = ft_init(ac - 1, av + 1, piles);
}
