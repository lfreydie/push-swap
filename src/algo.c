/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:54:23 by lefreydier        #+#    #+#             */
/*   Updated: 2023/01/31 01:07:59 by lefreydier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo_gd(t_infos *piles)
{
	int	i;

	i = 0;
	while (i++ < (piles->size / 2))
		mv_pb(piles);
	
}
