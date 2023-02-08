/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst_mv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:35:36 by lfreydie          #+#    #+#             */
/*   Updated: 2023/02/08 09:43:12 by lefreydier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_show_mouvs(t_infos *piles)
{
	t_mouvs	*cmd;

	if (!piles->mouvs)
		return (0);
	cmd = piles->mouvs;
	while (cmd)
	{
		write(1, cmd->mv, ft_strlen(cmd->mv));
		write(1, "\n", 1);
		cmd = cmd->next;
	}
	return (1);
}

t_mouvs	*ft_lstnew_mv(char *content)
{
	t_mouvs	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->mv = content;
	new->next = NULL;
	return (new);
}

t_mouvs	*ft_lstadd_back_mv(t_mouvs *lst, char *content)
{
	t_mouvs	*tmp;
	t_mouvs	*new;

	if (lst)
	{
		tmp = ft_lstlast_mv(lst);
		new = ft_lstnew_mv(content);
		if (!new)
			return (NULL);
		tmp->next = new;
	}
	return (new);
}

t_mouvs	*ft_lstlast_mv(t_mouvs *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
