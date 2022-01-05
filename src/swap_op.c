/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:13:00 by mderome           #+#    #+#             */
/*   Updated: 2021/12/25 14:29:15 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_swap(int *a, int *b)
{
	if (a[0] > a[1] && a[0] < a[2])
		return (1);
	if (b[0] < b[1] && b[1] < a[0])
		return (1);
	return (0);
}

void	swap_op(int *a, int *b, t_swap *swp)
{
	if (((a[0] > a[1] && a[0] < a[2]) || (b[0] < b[1] && b[1] < a[0]))
		&& b[0] > a[1])
	{
		swap_a(a, swp);
		swap_b(b, swp);
		write(1, "ss\n", 3);
	}
	else if (a[0] > a[1] && a[0] < a[2])
	{
		swap_a(a, swp);
		write(1, "sa\n", 3);
	}
	else if (b[0] < b[1] && b[1] < a[0])
	{
		swap_b(b, swp);
		write(1, "sb\n", 3);
	}
}
