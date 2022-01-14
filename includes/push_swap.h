/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:49:08 by mderome           #+#    #+#             */
/*   Updated: 2022/01/14 09:15:23 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"
# include <limits.h>

typedef struct s_swap
{
	int	sizetab;
	int	sizetab_a;
	int	sizetab_b;
	int	min;
	int	max;
	int	mid;
	int	count;
	int	nb;
}				t_swap;

typedef struct s_pos
{
	int	nb;
	int	revers_a;
	int	revers_b;
	int	count;
	int	moov_a;
	int	moov_b;
}				t_pos;

typedef struct s_cherch
{
	int	first;
	int	last;
	int	len_list;
}				t_cherch;

int			check_tab_a(char **str);
int			check_digit(char *str);
long int	*itoa_tab(char **tab, t_swap *swp);
void		swap_a(int *a, t_swap *swp);
void		push_a(int *a, int *b, t_swap *swp);
void		rotate_a(int *a, t_swap *swp);
void		reverse_rotate_a(int *a, t_swap *swp);
void		swap_b(int *b, t_swap *swp);
void		push_b(int *a, int *b, t_swap *swp);
void		rotate_b(int *b, t_swap *swp);
void		reverse_rotate_b(int *b, t_swap *swp);
int			find_min(int *a, t_swap *swp);
void		algo_choice(long int *a, t_swap *swp);
int			check_tab(int *a, t_swap *swp);
void		algo_for_3(int *a, t_swap *swp);
void		algo_for_5(int *a, int *b, t_swap *swp);
int			find_next_nbr(int *a, int nbr, t_swap *swp);
void		swap_a_and_b(int *a, int *b, t_swap *swp);
void		reverse_rotate_a_and_b(int *a, int *b, t_swap *swp);
void		rotate_b_and_write(int *b, t_swap *swp);
int			check_swap(int *a, int *b);
void		swap_op(int *a, int *b, t_swap *swp);
int			check_rotate(int *a, int *b, t_swap *swp);
void		rotate_op(int *a, int *b, t_swap *swp);
int			check_push(int *a, int *b, t_swap *swp);
void		ft_free_tab_int(long int *tab, t_swap *swp);
void		ft_free_tab(int *tab);
void		print_tab(int *a, t_swap *swp);
void		algo_for_all(int *a, int *b, t_swap *swp);
void		go_op(int *a, int *b, t_swap *swp, t_pos *moov);
void		rotate_a_and_b(int *a, int *b, t_swap *swp);
void		init_pos(t_pos *pos);
void		find_min_max(int *b, t_swap *swp, t_pos *pos);
void		find_min_max_a(int *a, t_swap *swp, t_pos *pos);
void		find_better_moove(int *a, int *b, t_swap *swp, t_pos *moove);
void		good_luck(int *a, int *b, t_swap *swp, t_pos *moov);
void		reverse_rotate_all(int *a, int *b, t_swap *swp, t_pos *moov);
int			tab_len(char **tab);
void		ft_free(char **tab);
int			check_all_2(char **arg, int ac);

#endif
