/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:12:10 by lfreydie          #+#    #+#             */
/*   Updated: 2023/01/28 18:42:07 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isnbr(const char *str)
{
	long	i;
	long	nb;
	int		sign;

	i = 0;
	sign = 1;
	nb = 0;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		else
			nb = nb * 10 + (str[i] - 48);
		if (nb * sign > 2147483647 || nb * sign < -2147483648)
			return (0);
		i++;
	}
	return (1);
}
