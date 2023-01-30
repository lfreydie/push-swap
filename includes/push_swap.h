/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:54:52 by lfreydie          #+#    #+#             */
/*   Updated: 2023/01/30 15:55:26 by lefreydier       ###   ########.fr       */
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
int			*sort_tab(char **av, int len);
// parse.c
int			parse(char **av, int len);
// utils.c
int			ft_isnbr(const char *str);

#endif
