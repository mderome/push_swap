/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:13:45 by mderome           #+#    #+#             */
/*   Updated: 2021/12/25 14:52:54 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_push(int *a, int *b, t_swap *swp)
{
	if ((b[0] > b[1] && b[0] < a[0] && b[0] < a[swp->sizetab_a - 1])
		|| (b[0] > a[swp->sizetab_a - 1]
			&& swp->sizetab_b != 0) || (b[0] > a[0] && b[0] < a[1]))
	{
		if ((b[0] < a[0] && b[0] < a[1] && b[0] < a[2] && b[0] < a[3]
				&& b[0] < a[4]))
			return (0);
		if (swp->sizetab_b == 0)
			return (0);
		return (1);
	}
	return (0);
}

void	rotate_a_and_b(int *a, int *b, t_swap *swp)
{
	rotate_a(a, swp);
	rotate_b(b, swp);
	write(1, "rr\n", 3);
}
