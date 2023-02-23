/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:44:37 by lfreydie          #+#    #+#             */
/*   Updated: 2023/02/23 17:56:43 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus.h"

int	ft_exec(t_infos *piles)
{
	char	*mouv;
	int		r;

	mouv = "Salut";
	while (mouv)
	{
		mouv = get_next_line(0);
		if (mouv)
		{
			r = ft_exec_cmd(piles, mouv);
			free(mouv);
			if (!r)
				return (0);
		}
	}
	return (1);
}

int	ft_exec_cmd(t_infos *piles, char *mouv)
{
	if (ft_cmp(mouv, "sa\n"))
		mv_sa(piles);
	else if (ft_cmp(mouv, "sb\n"))
		mv_sb(piles);
	else if (ft_cmp(mouv, "ss\n"))
		mv_ss(piles);
	else if (ft_cmp(mouv, "pa\n"))
		mv_pa(piles);
	else if (ft_cmp(mouv, "pb\n"))
		mv_pb(piles);
	else if (ft_cmp(mouv, "ra\n"))
		mv_ra(piles);
	else if (ft_cmp(mouv, "rb\n"))
		mv_rb(piles);
	else if (ft_cmp(mouv, "rr\n"))
		mv_rr(piles);
	else if (ft_cmp(mouv, "rra\n"))
		mv_rra(piles);
	else if (ft_cmp(mouv, "rrb\n"))
		mv_rrb(piles);
	else if (ft_cmp(mouv, "rrr\n"))
		mv_rrr(piles);
	else
		return (0);
	return (1);
}
