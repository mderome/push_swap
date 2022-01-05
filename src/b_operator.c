/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_operator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 09:51:57 by mderome           #+#    #+#             */
/*   Updated: 2021/12/25 14:28:50 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(int *b, t_swap *swp)
{
	int	tmp;

	if (swp->sizetab_b < 2)
		return ;
	tmp = b[0];
	b[0] = b[1];
	b[1] = tmp;
}

void	push_b(int *a, int *b, t_swap *swp)
{
	int	i;
	int	j;
	int	tmp;

	i = swp->sizetab_b + 1;
	tmp = a[0];
	while (i)
	{
		j = i - 1;
		b[i] = b[j];
		i--;
	}
	b[i] = tmp;
	i = 0;
	while (i < swp->sizetab_a - 1)
	{
		j = i + 1;
		a[i] = a[j];
		i++;
	}
	a[i] = 0;
	swp->sizetab_b += 1;
	swp->sizetab_a -= 1;
}

void	rotate_b(int *b, t_swap *swp)
{
	int	i;
	int	j;
	int	tmp;

	if (swp->sizetab_b < 2)
		return ;
	i = 0;
	tmp = b[0];
	while (i < swp->sizetab_b - 1)
	{
		j = i + 1;
		b[i] = b[j];
		i++;
	}
	b[i] = tmp;
}

void	reverse_rotate_b(int *b, t_swap *swp)
{
	int	i;
	int	j;
	int	tmp;

	if (swp->sizetab_b < 2)
		return ;
	i = swp->sizetab_b - 1;
	tmp = b[i];
	while (i)
	{
		j = i - 1;
		b[i] = b[j];
		i--;
	}
	b[i] = tmp;
}

void	reverse_rotate_a_and_b(int *a, int *b, t_swap *swp)
{
	if (swp->sizetab_b < 2)
		return ;
	reverse_rotate_a(a, swp);
	reverse_rotate_b(b, swp);
	write(1, "rrr\n", 4);
}
