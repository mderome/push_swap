/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:10:56 by mderome           #+#    #+#             */
/*   Updated: 2022/01/14 09:18:01 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_all_2(char **arg, int ac)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (arg[i] != NULL && i < ac)
	{
		j = 0;
		while (arg[i][j] != '\0')
		{
			if (ft_isdigit(arg[i][j]) == 0 && arg[i][j] != ' '
					&& arg[i][j] != '+' && arg[i][j] != '-')
				return (1);
			else if ((arg[i][j] == '-' && (arg[i][j + 1] < '0'
				|| arg[i][j + 1] > '9')))
				return (1);
			else if (arg[i][j] == '+' && (arg[i][j + 1] < '0'
				|| arg[i][j + 1] > '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	find_min2(int *a, t_swap *swp)
{
	int	i;

	i = 0;
	while (a[i] != swp->min && i < swp->sizetab_a)
		i++;
	return (i);
}

void	go_rotate(int *a, t_swap *swp)
{
	int	i;

	i = find_min2(a, swp);
	if (i > (swp->sizetab_a / 2))
	{
		while (a[0] != swp->min)
		{
			rotate_a(a, swp);
			write(1, "ra\n", 3);
		}
	}
	else
	{
		while (a[0] != swp->min)
		{
			reverse_rotate_a(a, swp);
			write(1, "rra\n", 4);
		}
	}
}

void	rotate_all(int *a, int *b, t_swap *swp, t_pos *moov)
{
	while (moov->count > 1 && b[0] != moov->nb && moov->moov_a > 0)
	{
		rotate_a_and_b(a, b, swp);
		moov->count--;
		moov->moov_a--;
	}
	while (b[0] != moov->nb)
	{
		rotate_b(b, swp);
		write(1, "rb\n", 3);
	}
	while (!(a[swp->sizetab_a - 1] < moov->nb && a[0] > moov->nb))
	{
		rotate_a(a, swp);
		write(1, "ra\n", 3);
	}
	push_a(a, b, swp);
	write(1, "pa\n", 3);
}

void	go_op(int *a, int *b, t_swap *swp, t_pos *moov)
{
	if (swp->sizetab_b == 0)
	{
		go_rotate(a, swp);
		return ;
	}
	if (moov->revers_a && moov->revers_b)
		reverse_rotate_all(a, b, swp, moov);
	else if (!moov->revers_a && !moov->revers_b)
		rotate_all(a, b, swp, moov);
	else
		good_luck(a, b, swp, moov);
}
