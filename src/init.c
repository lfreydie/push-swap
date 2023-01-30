/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:51:05 by lfreydie          #+#    #+#             */
/*   Updated: 2023/01/31 00:48:47 by lefreydier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_infos	*init(int len, char **av)
{
	t_infos	*piles;

	piles = malloc(sizeof(*piles));
	if (!piles)
		return (NULL);
	piles->b = NULL;
	if (parse(av, len))
	{
		piles->tab = create_tab(av, len);
		piles->a = init_data(av, len);
		if (!piles->a || !piles->tab)
			return (ft_free_piles(piles), write(1, "Error\n", 6), NULL);
		piles->size = len;
	}
	else
		return (ft_free_piles(piles), write(1, "Error\n", 6), NULL);
	return (piles);
}

t_element	*init_data(char **av, int len)
{
	t_element	*list;
	t_element	*new;
	int			i;

	i = 0;
	if (!list)
	{
		list = ft_lstnew(atoi(av[i]));
		if (!list)
			return (NULL);
		i++;
	}
	while (i < len)
	{
		new = ft_lstadd_back(list, new, ft_atoi(av[i]));
		if (!new)
			return (NULL);
		i++;
	}
	return (list);
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
	sort_tab(tab, len);
	return (tab);
}

void	sort_tab(int *tab, int len)
{
	int	i;
	int	j;
	int	tmp;

	if (!tab)
		return (NULL);
	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			else if (tab[i] == tab[j])
				return (NULL);
			j++;
		}
		i++;
	}
}
