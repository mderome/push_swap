/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_choice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 11:27:51 by mderome           #+#    #+#             */
/*   Updated: 2022/01/12 10:32:17 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*long_to_int(long int *a, t_swap *swp)
{
	int	*tmp;
	int	i;

	i = 0;
	tmp = malloc(sizeof(int) * swp->sizetab_a);
	if (!tmp)
		return (0);
	while (i < swp->sizetab_a)
	{
		tmp[i] = a[i];
		i++;
	}
	return (tmp);
}

void	algo_for_3(int *a, t_swap *swp)
{
	while (check_tab(a, swp) != 0)
	{
		if (a[0] < a[1] && swp->sizetab_a == 2)
		{
			swap_a(a, swp);
			write(1, "sa\n", 3);
			break ;
		}
		if (swp->sizetab_a == 3 && (a[0] > a[1] && a[1] < a[2] && a[0] < a[2]))
		{
			swap_a(a, swp);
			write(1, "sa\n", 3);
		}
		else if (swp->sizetab_a == 3 && ((a[0] > a[1] && a[0] > a[2]
					&& a[1] < a[2]) || (a[0] > a[1] && a[1] > a[2])))
		{
			rotate_a(a, swp);
			write(1, "ra\n", 3);
		}
		else
		{
			reverse_rotate_a(a, swp);
			write(1, "rra\n", 4);
		}
	}
}

void	algo_choice(long int *a, t_swap *swp)
{
	int	*b;
	int	*new_a;

	new_a = long_to_int(a, swp);
	if (check_tab(new_a, swp) == 0)
	{
		ft_free_tab(new_a);
		return ;
	}
	b = (int *)malloc(sizeof(int) * (swp->sizetab_a + 1));
	if (!b)
		return ;
	swp->min = find_min(new_a, swp);
	if (swp->sizetab_a <= 3)
		algo_for_3(new_a, swp);
	else if (swp->sizetab_a <= 5)
		algo_for_5(new_a, b, swp);
	else
		algo_for_all(new_a, b, swp);
	ft_free_tab(new_a);
	ft_free_tab(b);
}
