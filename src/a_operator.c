/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_operator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 09:52:02 by mderome           #+#    #+#             */
/*   Updated: 2021/12/25 14:27:44 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(int *a, t_swap *swp)
{
	int	tmp;

	if (swp->sizetab_a < 2)
		return ;
	tmp = a[0];
	a[0] = a[1];
	a[1] = tmp;
}

void	push_a(int *a, int *b, t_swap *swp)
{
	int	i;
	int	j;
	int	tmp;

	i = swp->sizetab_a;
	tmp = b[0];
	while (i)
	{
		j = i - 1;
		a[i] = a[j];
		i--;
	}
	a[i] = tmp;
	i = 0;
	while (i < swp->sizetab_b - 1)
	{
		j = i + 1;
		b[i] = b[j];
		i++;
	}
	b[i] = 0;
	swp->sizetab_a += 1;
	swp->sizetab_b -= 1;
}

void	rotate_a(int *a, t_swap *swp)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = a[0];
	while (i < swp->sizetab_a - 1)
	{
		j = i + 1;
		a[i] = a[j];
		i++;
	}
	a[i] = tmp;
}

void	reverse_rotate_a(int *a, t_swap *swp)
{
	int	i;
	int	j;
	int	tmp;

	i = swp->sizetab_a - 1;
	tmp = a[i];
	while (i)
	{
		j = i - 1;
		a[i] = a[j];
		i--;
	}
	a[i] = tmp;
}

void	swap_a_and_b(int *a, int *b, t_swap *swp)
{
	swap_a(a, swp);
	swap_b(b, swp);
	write(1, "ss\n", 3);
}
