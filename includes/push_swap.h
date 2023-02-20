/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:54:52 by lfreydie          #+#    #+#             */
/*   Updated: 2023/02/20 16:28:05 by lfreydie         ###   ########.fr       */
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
	int					rank;
	int					range;
	struct s_element	*prev;
	struct s_element	*next;
}	t_element;

typedef struct s_mouvs
{
	char			*mv;
	struct s_mouvs	*next;
}	t_mouvs;

typedef struct s_infos
{
	t_element	*a;
	t_element	*b;
	int			*tab;
	int			size;
	int			size_a;
	int			size_b;
	t_mouvs		*mouvs;
}	t_infos;

// init.c
t_infos		*init(int ac, char **av);
t_element	*init_data(char **av, int len, int *tab);
int			*create_tab(char **av, int len);
int			sort_tab(int *tab, int len);
// algo.c
void		algo(t_infos *piles);
void		algo_pt(t_infos *piles);
void		pb_pre_tri(t_infos *piles);
// utils.c
int			ft_isnbr(const char *str);
int			ft_atoi(const char *nptr);
int			ft_strlen(char *s);
int			stock(t_infos *piles, int success, char *cmd);
// utils_lst.c
t_element	*ft_lstnew(int nombre, int *tab);
t_element	*ft_lstadd_back(t_element *lst, int nombre, int *tab);
t_element	*ft_lstlast(t_element *lst);
int			find_range_up(t_element *lst);
// utils_lst_mv.c
int			ft_show_mouvs(t_infos *piles);
int			ft_cmp(t_mouvs *mv, char *cmd);
t_mouvs		*ft_lstnew_mv(char *content);
t_mouvs		*ft_lstadd_back_mv(t_mouvs *lst, char *content);
t_mouvs		*ft_lstlast_mv(t_mouvs *lst);
// test.c
int			correct(t_element *lst);
int			parse(char **av, int len);
// push_a.c
void		ft_pa(t_infos *piles);
t_element	*find_elem(t_infos *piles);
int			count_mv(t_infos *piles, int mv_a, int mv_b);
void		ft_mv_pa(t_infos *piles, int mv_a, int mv_b);
// push_b.c
void		ft_push_b(t_infos *piles, t_element *lst, int limit);
void		organize_b(t_infos *piles, int chunk, int reste);
int			ft_find_count_ra(t_element	*lst, int limit);
int			ft_find_count_rra(t_element	*lst, int limit);
// free.c
void		ft_free_piles(t_infos *piles);
void		ft_free_element(t_element *lst);
// count_mv.c
int			is_framed(int obj, int first, int last);
int			test_mv_ra(t_element *first, t_element *last);
int			count_ra(t_element *first, t_element *last, t_element *obj);
int			ft_count_a(t_infos *piles, t_element *elem);
int			ft_count_b(t_infos *piles, t_element *elem);
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
