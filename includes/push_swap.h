/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:54:52 by lfreydie          #+#    #+#             */
/*   Updated: 2023/02/07 15:15:28 by lfreydie         ###   ########.fr       */
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
	int					rank;
	struct s_element	*prev;
	struct s_element	*next;
}	t_element;

typedef struct s_infos
{
	t_element	*a;
	t_element	*b;
	int			*tab;
	int			size;
	int			size_a;
	int			size_b;
}	t_infos;

// init.c
t_infos		*init(int ac, char **av);
t_element	*init_data(char **av, int len, int *tab);
int			*create_tab(char **av, int len);
int			sort_tab(int *tab, int len);
// parse.c
int			parse(char **av, int len);
// algo.c
void		algo(t_infos *piles);
void		algo_pt(t_infos *piles);
void		algo_gd(t_infos *piles);
// utils.c
int			ft_isnbr(const char *str);
int			ft_atoi(const char *nptr);
int			ft_strlen(char *s);
int			ft_show(int success, char *cmd);
// utils_lst.c
t_element	*ft_lstnew(int nombre, int *tab);
t_element	*ft_lstadd_back(t_element *lst, int nombre, int *tab);
t_element	*ft_lstlast(t_element *lst);
// test.c
int			is_correct(t_element *lst);
// free.c
void		ft_free_piles(t_infos *piles);
void		ft_free_element(t_element *lst);
// mouvs_swap.c
int			mv_sa(t_infos *piles);
int			mv_sb(t_infos *piles);
int			mv_ss(t_infos *piles);
// mouvs_push.c
int			mv_pa(t_infos *piles);
int			mv_pb(t_infos *piles);
// mouvs_rotate.c
int			mv_ra(t_infos *piles);
int			mv_rb(t_infos *piles);
int			mv_rr(t_infos *piles);
// mouvs_rev_rot.c
int			mv_rra(t_infos *piles);
int			mv_rrb(t_infos *piles);
int			mv_rrr(t_infos *piles);

#endif
