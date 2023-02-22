/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:51:05 by lfreydie          #+#    #+#             */
/*   Updated: 2023/02/22 15:39:20 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_infos	*init(int len, char **av)
{
	t_infos	*piles;

	piles = malloc(sizeof(*piles));
	if (!piles)
		return (write(1, "Error\n", 6), NULL);
	piles->b = NULL;
	if (parse(av, len))
	{
		piles->tab = create_tab(av, len);
		if (!piles->tab)
			return (ft_free_piles(piles), write(1, "Error\n", 6), NULL);
		piles->a = init_data(av, len, piles->tab);
		if (!piles->a)
			return (ft_free_piles(piles), write(1, "Error\n", 6), NULL);
		piles->b = NULL;
		piles->mouvs = NULL;
		piles->size = len;
		piles->size_a = piles->size;
		piles->size_b = 0;
	}
	else
		return (ft_free_piles(piles), write(1, "Error\n", 6), NULL);
	return (piles);
}

t_element	*init_data(char **av, int len, int *tab)
{
	t_element	*list;
	t_element	*new;
	int			i;

	i = 0;
	list = ft_lstnew(ft_atoi(av[i]), tab, len);
	if (!list)
		return (NULL);
	i++;
	while (i < len)
	{
		new = ft_lstadd_back(list, ft_atoi(av[i]), tab, len);
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
	int	success;

	i = 0;
	tab = malloc(sizeof(tab) * len);
	if (!tab)
		return (NULL);
	while (i < len)
	{
		tab[i] = ft_atoi(av[i]);
		i++;
	}
	success = sort_tab(tab, len);
	if (!success)
		return (NULL);
	return (tab);
}

int	sort_tab(int *tab, int len)
{
	int	i;
	int	j;
	int	tmp;

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
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
