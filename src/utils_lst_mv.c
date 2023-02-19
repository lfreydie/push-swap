/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst_mv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morganeberthod <morganeberthod@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:35:36 by lfreydie          #+#    #+#             */
/*   Updated: 2023/02/19 10:01:24 by morganebert      ###   ########.fr       */
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
	printf("elem nv mv : %s \n", new->mv);
	return (new);
}

t_mouvs	*ft_lstadd_back_mv(t_mouvs *lst, char *content)
{
	t_mouvs	*tmp;
	t_mouvs	*new;

	new = NULL;
	if (lst)
	{
		printf("On veut ajouter %s | ft_lst_add_back_mv : \n", content);
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
	{
		printf("elem mv : %s , ", lst->mv);
		lst = lst->next;
	}
	printf("elem mv : %s\n", lst->mv);
	return (lst);
}
