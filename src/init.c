/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:51:05 by lfreydie          #+#    #+#             */
/*   Updated: 2023/01/30 16:11:00 by lefreydier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_infos	*init(int len, char **av, t_infos *piles)
{
	piles = malloc(sizeof(*piles));
	if (!piles)
		return (NULL);
	piles->b = NULL;
	if (parse(av, len))
	{
		piles->a = init_data(av, len);
		piles->tab = create_tab(av, len);
		piles->sort_tab = sort_tab(piles->tab, len);
		if (!piles->a || !piles->tab || !piles->sort_tab)
			return (ft_free_piles(piles), write(1, "Error\n", 6), NULL);
	}
	else
		return (ft_free_piles(piles), write(1, "Error\n", 6), NULL);
}

t_element	*init_data(char **av, int len)
{
	t_element	*new;
	t_element	*first;
	int			i;

	while (i < len)
	{
		new = malloc(sizeof(*new));
		if (!new)
			return (ft_clear(first), NULL);
		if (i == 0)
		{
			ft_lstnew();
		}
	}
	return (first);
}

int	*create_tab(char **av, int len)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(*tab) * len);
	if (!tab)
		return (NULL);
	while (i < len)
	{
		tab[i] = ft_atoi(av[i]);
		i++;
	}
	return (tab);
}

int	*sort_tab(char **av, int len)
{
	int	i;
	int	j;
	int	tmp;
	int	*sort_tab;

	sort_tab = create_tab(av, len);
	if (!sort_tab)
		return (NULL);
	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (sort_tab[i] > sort_tab[j])
			{
				tmp = sort_tab[i];
				sort_tab[i] = sort_tab[j];
				sort_tab[j] = tmp;
			}
			else if (sort_tab[i] == sort_tab[j])
				return (NULL);
			j++;
		}
		i++;
	}
	return (sort_tab);
}
