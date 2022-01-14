/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:13:45 by mderome           #+#    #+#             */
/*   Updated: 2022/01/14 09:27:46 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0' && str[i + 1] != 0)
		i++;
	if (ft_strlen(str + i) > 12)
		return (1);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '\0')
		return (1);
	return (0);
}

int	check_tab_a(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str_is_num(str[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

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
