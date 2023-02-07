/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:55:50 by lefreydier        #+#    #+#             */
/*   Updated: 2023/02/07 11:52:15 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_correct(t_element *lst)
{
	while (lst->next)
	{
		if (lst->nombre > lst->next->nombre)
			return (-1);
		else
			lst = lst->next;
	}
	return (0);
}
