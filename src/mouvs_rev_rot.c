/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvs_rev_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:31:36 by lefreydier        #+#    #+#             */
/*   Updated: 2023/02/20 12:02:44 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	mv_rra(t_infos *piles)
{
	t_element	*tmp;
	t_element	*last;

	printf("on veut last de piles->a | mv_rra : \n\n\n");
	tmp = ft_lstlast(piles->a);
	printf("element a mettre en premier : %d \n\n\n", tmp->nombre);
	printf("element a mettre en premier : %d \n\n\n", tmp->prev->nombre);
	last = tmp->prev;
	printf("element a mettre en dernier : %d \n\n\n", last->nombre);
	last->next = NULL;
	piles->a->prev = tmp;
	tmp->next = piles->a;
	tmp->prev = NULL;
	piles->a = tmp;
	return (1);
}

int	mv_rrb(t_infos *piles)
{
	t_element	*tmp;
	t_element	*last;

	printf("on veut last de piles->b | mv_rrb : \n");
	tmp = ft_lstlast(piles->b);
	last = tmp->prev;
	last->next = NULL;
	piles->b->prev = tmp;
	tmp->next = piles->b;
	tmp->prev = NULL;
	piles->b = tmp;
	return (1);
}

int	mv_rrr(t_infos *piles)
{
	mv_rra(piles);
	mv_rrb(piles);
	return (1);
}
