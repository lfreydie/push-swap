/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:54:52 by lfreydie          #+#    #+#             */
/*   Updated: 2023/01/28 18:42:18 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_element
{
	int					nombre;
	int					position;
	struct s_element	*next;
}	t_element;

typedef struct s_infos
{
	t_element	*a;
	t_element	*b;
	int			*tab;
	int			*sort_tab;
}	t_infos;

// init.c
t_infos		*init(int ac, char **av, t_infos *piles);
t_element	*init_data(char **av, int len);
int			*create_tab(char **av, int len);
int			*sort_tab(int *tab, int len);
// parse.c
int			parse(char **av, int len);
// utils.c
int			ft_isnbr(const char *str);

#endif
