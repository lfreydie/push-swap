/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:12:10 by lfreydie          #+#    #+#             */
/*   Updated: 2023/02/07 22:27:48 by lefreydier       ###   ########.fr       */
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
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		else
			nb = nb * 10 + (str[i] - 48);
		if (nb * sign > 2147483647 || nb * sign < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - 48;
		i++;
	}
	return (sign * res);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_show(t_infos *piles, int success, char *cmd)
{
	t_mouvs	*new;

	if (success)
	{
		if (!piles->mouvs)
		{
			new = ft_lstnew_mv(cmd);
			piles->mouvs = new;
		}
		else
			new = ft_lstadd_back_mv(piles->mouvs, cmd);
		if (!new)
			return (0);
	}
	return (success);
}
