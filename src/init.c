/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:51:05 by lfreydie          #+#    #+#             */
/*   Updated: 2023/01/28 18:52:05 by lfreydie         ###   ########.fr       */
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
		if (!piles->a || !piles->tab)
			return (free(piles), write(1, "Error\n", 6), NULL);
		piles->sort_tab = sort_tab(piles->tab, len);
		if (!piles->sort_tab)
			return (free(piles->tab), free(piles), write(1, "Error\n", 6), NULL);
	}
	else
		return (free(piles), write(1, "Error\n", 6), NULL);
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


int	*sort_tab(int *tab, int len)
{
	int	i;
	int	j;
	int	tmp;
	int	*sort_tab;

	sort_tab = malloc(sizeof(*sort_tab) * len);
	if (!sort_tab)
		return (NULL);
	ft_memcpy(sort_tab, tab, len);
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
				return (free(sort_tab), NULL);
			j++;
		}
		i++;
	}
	return (sort_tab);
}
