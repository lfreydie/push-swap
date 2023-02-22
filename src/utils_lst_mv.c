/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst_mv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:35:36 by lfreydie          #+#    #+#             */
/*   Updated: 2023/02/22 16:00:06 by lfreydie         ###   ########.fr       */
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
		if ((ft_cmp(cmd, "rra") && ft_cmp(cmd->next, "rrb")) || \
			(ft_cmp(cmd, "rrb") && ft_cmp(cmd->next, "rra")))
		{
			cmd = cmd->next;
			write(1, "rrr", 3);
		}
		else if ((ft_cmp(cmd, "ra") && ft_cmp(cmd->next, "rb")) || \
			(ft_cmp(cmd, "rb") && ft_cmp(cmd->next, "ra")))
		{
			cmd = cmd->next;
			write(1, "rr", 2);
		}
		else
			write(1, cmd->mv, ft_strlen(cmd->mv));
		write(1, "\n", 1);
		cmd = cmd->next;
	}
	return (1);
}

int	ft_cmp(t_mouvs *mouv, char *cmd)
{
	char	*mv;
	int		i;

	if (!mouv)
		return (0);
	mv = mouv->mv;
	i = 0;
	while (mv[i] || cmd[i])
	{
		if (mv[i] != cmd[i])
			return (0);
		i++;
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

	new = NULL;
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
