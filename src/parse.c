/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:06:15 by lfreydie          #+#    #+#             */
/*   Updated: 2023/01/28 15:41:36 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
