/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:25:06 by mderome           #+#    #+#             */
/*   Updated: 2021/12/25 15:00:59 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_rotate(int *a, int *b, t_swap *swp)
{
	if (((b[0] < a[swp->sizetab_a - 1] && b[0] > a[swp->sizetab_a - 2]
				&& b[0] > b[1]) || a[0] > a[swp->sizetab_a - 1])
		&& check_push(a, b, swp) == 0)
		return (1);
	return (0);
}

void	rotate_op(int *a, int *b, t_swap *swp)
{
	if ((((b[0] < a[swp->sizetab_a - 1] && b[0] > a[swp->sizetab_a - 2]
					&& b[0] > b[1]) || (a[0] > (a[swp->sizetab_a - 1]
						&& swp->sizetab_b == 0))) && b[0] > a[0])
		&& (a[0] > a[swp->sizetab_a - 1] || b[0] < a[swp->sizetab_a - 1]))
	{
		rotate_a(a, swp);
		rotate_b(b, swp);
		write(1, "RRR\n", 4);
	}
	else if (((b[0] < a[swp->sizetab_a - 1] && b[0] > a[swp->sizetab_a - 2]
				&& b[0] > b[1]) || (a[0] > (a[swp->sizetab_a - 1]
					&& swp->sizetab_b == 0))) && b[0] > a[0])
	{
		reverse_rotate_a(a, swp);
		write(1, "RRA\n", 4);
	}
	else if ((a[0] > a[swp->sizetab_a - 1] || b[0] < a[swp->sizetab_a - 1])
		&& check_push(a, b, swp) == 0)
	{
		rotate_a(a, swp);
		write(1, "RA\n", 3);
	}
}
