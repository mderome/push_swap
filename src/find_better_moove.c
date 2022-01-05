/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_better_moove.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:33:13 by mderome           #+#    #+#             */
/*   Updated: 2021/12/27 10:32:40 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_moove(int count_a, int count_b, t_swap *swp, t_pos *moov)
{
	moov->revers_a = 0;
	moov->revers_b = 0;
	if (count_a > (swp->sizetab_a / 2))
	{
		count_a = swp->sizetab_a - count_a;
		moov->revers_a = 1;
	}
	if (count_b > (swp->sizetab_b / 2))
	{
		count_b = swp->sizetab_b - count_b;
		moov->revers_b = 1;
	}
	if ((moov->revers_a && moov->revers_b) || (!moov->revers_a
			&& !moov->revers_b))
	{
		if (count_a < count_b)
			moov->count = count_b;
		else
			moov->count = count_a;
	}
	else
		moov->count = count_a + count_b;
}

void	take_moove(int *a, t_swap *swp, t_pos *moove, int count)
{
	int	i;

	i = 0;
	while (i < swp->sizetab_a)
	{
		if (i == 0)
		{
			if (swp->nb > a[swp->sizetab_a - 1] && swp->nb < a[i])
			{
				make_moove(i, count, swp, moove);
				moove->moov_a = i;
				return ;
			}
		}
		else
		{
			if (swp->nb > a[i - 1] && swp->nb < a[i])
			{
				make_moove(i, count, swp, moove);
				moove->moov_a = i;
				return ;
			}
		}
		i++;
	}
}

void	swap_count(t_pos *tmp, t_pos *moov, int count_b, int nb)
{
	moov->nb = nb;
	moov->count = tmp->count;
	moov->revers_a = tmp->revers_a;
	moov->revers_b = tmp->revers_b;
	moov->moov_a = tmp->moov_a;
	moov->moov_b = count_b;
}

void	find_better_moove(int *a, int *b, t_swap *swp, t_pos *moove)
{
	int		i;
	t_pos	tmp;

	i = 0;
	init_pos(&tmp);
	init_pos(moove);
	swp->nb = b[i];
	take_moove(a, swp, moove, i + 1);
	moove->count = i + 1 + moove->moov_a;
	moove->nb = b[i];
	i++;
	while (i < swp->sizetab_b - 1)
	{
		swp->nb = b[i];
		take_moove(a, swp, &tmp, i + 1);
		if (tmp.count < moove->count)
			swap_count(&tmp, moove, i + 1, b[i]);
		i++;
	}
	if (moove->moov_a > (swp->sizetab_a / 2))
	{
		moove->moov_a = swp->sizetab_a - moove->moov_a;
		moove->revers_a = 1;
	}
}
