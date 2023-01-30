/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:54:52 by lfreydie          #+#    #+#             */
/*   Updated: 2023/01/31 00:40:17 by lefreydier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_element
{
	int					nombre;
	int					position;
	struct s_element	*prev;
	struct s_element	*next;
}	t_element;

typedef struct s_infos
{
	t_element	*a;
	t_element	*b;
	int			*tab;
}	t_infos;

// init.c
t_infos		*init(int ac, char **av);
t_element	*init_data(char **av, int len);
int			*create_tab(char **av, int len);
void		sort_tab(int *tab, int len);
// parse.c
int			parse(char **av, int len);
// utils.c
int			ft_isnbr(const char *str);
int			ft_atoi(const char *nptr);
// utils_lst.c
t_element	*ft_lstnew(int nombre);
t_element	*ft_lstadd_back(t_element *lst, t_element *new, int nombre);
t_element	*ft_lstlast(t_element *lst);
// free.c
void		ft_free_piles(t_infos *piles);
void		ft_free_element(t_element *lst);

#endif
