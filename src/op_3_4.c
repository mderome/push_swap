/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_3_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:10:56 by mderome           #+#    #+#             */
/*   Updated: 2021/12/25 14:54:21 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_count_b(int *b, t_swap *swp, t_pos *moov)
{
	int	i;

	i = 0;
	while (b[i] != moov->nb)
		i++;
	if (i > (swp->sizetab_b / 2))
	{
		moov->moov_b = swp->sizetab_b - i + 1;
		moov->revers_b = 1;
	}
	else
	{
		moov->moov_b = i + 1;
		moov->revers_b = 0;
	}
}

void	moov_rotate_b(int *b, t_swap *swp, t_pos *moov)
{
	if (moov->revers_b)
	{
		while (moov->moov_b > 1)
		{
			reverse_rotate_b(b, swp);
			write(1, "rrb\n", 4);
			moov->moov_b--;
		}
	}
	else
	{
		while (moov->moov_b > 1)
		{
			rotate_b(b, swp);
			write(1, "rb\n", 3);
			moov->moov_b--;
		}
	}
}

void	reverse_rotate_all(int *a, int *b, t_swap *swp, t_pos *moov)
{
	while (moov->count > 1 && b[0] != moov->nb && moov->moov_a > 0)
	{
		reverse_rotate_a_and_b(a, b, swp);
		moov->count--;
		moov->moov_a--;
	}
	while (b[0] != moov->nb)
	{
		reverse_rotate_b(b, swp);
		write(1, "rrb\n", 4);
	}
	while (!(a[swp->sizetab_a - 1] < moov->nb && a[0] > moov->nb))
	{
		reverse_rotate_a(a, swp);
		write(1, "rra\n", 4);
	}
	push_a(a, b, swp);
	write(1, "pa\n", 3);
}

void	good_luck2(int *a, int *b, t_swap *swp, t_pos *moov)
{
	while (moov->moov_a)
	{
		rotate_a(a, swp);
		write(1, "ra\n", 3);
		moov->moov_a--;
	}
	find_count_b(b, swp, moov);
	moov_rotate_b(b, swp, moov);
	push_a(a, b, swp);
	write(1, "pa\n", 3);
}

void	good_luck(int *a, int *b, t_swap *swp, t_pos *moov)
{
	if (moov->revers_a && !moov->revers_b)
	{
		while ((moov->moov_a))
		{
			reverse_rotate_a(a, swp);
			write(1, "rra\n", 4);
			moov->moov_a--;
		}
		find_count_b(b, swp, moov);
		moov_rotate_b(b, swp, moov);
		push_a(a, b, swp);
		write(1, "pa\n", 3);
	}
	else
		good_luck2(a, b, swp, moov);
}
