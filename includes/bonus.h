/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:47:13 by lfreydie          #+#    #+#             */
/*   Updated: 2023/02/23 18:40:57 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_element
{
	int					nombre;
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
// exec.c
int			ft_exec(t_infos *piles);
int			ft_exec_cmd(t_infos *piles, char *mouv);
// utils.c
int			ft_isnbr(const char *str);
int			ft_atoi(const char *nptr);
int			ft_strlen(char *s);
int			ft_cmp(char *mouv, char *cmd);
// utils_lst.c
t_element	*ft_lstnew(int nombre, int *tab, int len);
t_element	*ft_lstadd_back(t_element *lst, int nombre, int *tab, int len);
t_element	*ft_lstlast(t_element *lst);
int			find_range_up(t_element *lst);
// test.c
int			correct(t_element *lst);
int			parse(char **av, int len);
int			ft_check_piles(t_infos *piles);
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
// get_next_line.c
char		*get_next_line(int fd);
char		*ft_next(char *buffer);
char		*ft_line(char *buffer);
char		*ft_read(int fd, char *buffer);
char		*ft_tmp(char *tmp, char *buffer);
// get_next_line_utils.c
int			ft_strchr(char *str, char c);
char		*ft_strjoin(char *s1, char *s2);

#endif
