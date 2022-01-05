/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:46:46 by mderome           #+#    #+#             */
/*   Updated: 2021/12/31 15:19:52 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_mid(int *a, t_swap *swp)
{
	int	i;
	int	tmp;
	int	tmp2;

	tmp = (swp->max + swp->min) / 2;
	tmp2 = (swp->max + swp->min) / 2;
	while (1)
	{
		i = -1;
		while (++i < swp->sizetab_a - 1)
		{
			if (tmp == a[i])
			{
				swp->mid = tmp;
				return ;
			}
			else if (tmp2 == a[i])
			{
				swp->mid = tmp2;
				return ;
			}
		}
		tmp++;
		tmp2--;
	}
}

void	find_min_max_mid(int *a, t_swap *swp)
{
	int	i;

	i = 0;
	swp->max = a[i];
	swp->min = a[i];
	while (i < swp->sizetab_a)
	{
		if (swp->max < a[i])
			swp->max = a[i];
		if (swp->min > a[i])
			swp->min = a[i];
		i++;
	}
	find_mid(a, swp);
}

void	push_all_b(int *a, int *b, t_swap *swp)
{
	while (swp->sizetab_a != 3)
	{
		if (a[0] != swp->min && a[0] != swp->max && a[0] != swp->mid)
		{
			push_b(a, b, swp);
			write(1, "pb\n", 3);
		}
		else if (a[0] == swp->min || a[0] == swp->max || a[0] == swp->mid)
		{
			rotate_a(a, swp);
			write(1, "ra\n", 3);
		}
	}
}

void	algo_basic(int *a, int *b, t_swap *swp)
{
	t_pos	moove;

	init_pos(&moove);
	find_min_max_mid(a, swp);
	push_all_b(a, b, swp);
	algo_for_3(a, swp);
	while (swp->sizetab_b != 0 || check_tab(a, swp) != 0)
	{
		if (swp->sizetab_b != 0)
			find_better_moove(a, b, swp, &moove);
		go_op(a, b, swp, &moove);
	}
}

void	algo_for_all(int *a, int *b, t_swap *swp)
{
	algo_basic(a, b, swp);
}
