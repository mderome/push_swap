/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:47:45 by mderome           #+#    #+#             */
/*   Updated: 2021/12/25 15:04:32 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_reverse_min(int *a, t_swap *swp)
{
	int	i;

	i = 0;
	while (i < swp->sizetab_a - 1)
	{
		if (a[swp->sizetab_a - 1] > a[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_min(int *a, t_swap *swp)
{
	int	i;

	i = 1;
	while (i < swp->sizetab_a)
	{
		if (a[0] > a[i])
			return (1);
		i++;
	}
	return (0);
}

void	algo_for_5_bis(int *a, int *b, t_swap *swp)
{
	if (b[0] < b[1])
	{
		rotate_b(b, swp);
		write(1, "rb\n", 3);
	}
	while (swp->sizetab_b != 0)
	{
		push_a(a, b, swp);
		write(1, "pa\n", 3);
	}
}

void	algo_for_5(int *a, int *b, t_swap *swp)
{
	while (swp->sizetab_a != 3)
	{
		if (check_min(a, swp) == 0)
		{
			push_b(a, b, swp);
			write(1, "pb\n", 3);
		}
		if (check_reverse_min(a, swp) == 0)
		{
			reverse_rotate_a(a, swp);
			write(1, "rra\n", 4);
		}
		else
		{
			rotate_a(a, swp);
			write(1, "ra\n", 3);
		}
	}
	algo_for_3(a, swp);
	algo_for_5_bis(a, b, swp);
}
