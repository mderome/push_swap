/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 09:52:09 by mderome           #+#    #+#             */
/*   Updated: 2022/01/12 16:49:08 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	if (i > 12)
		return (0);
	return (1);
}

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

long int	*itoa_tab(char **tab, t_swap *swp)
{
	int			i;
	long int	*ret;

	i = 0;
	swp->sizetab = tab_len(tab);
	ret = (long int *)malloc(sizeof(long int) * (swp->sizetab));
	if (!ret)
		return (0);
	while (i < swp->sizetab)
	{
		ret[i] = (long)ft_atoi(tab[i]);
		i++;
	}
	swp->sizetab_a = swp->sizetab;
	ft_free(tab);
	return (ret);
}

int	find_min(int *a, t_swap *swp)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = a[i];
	while (i < swp->sizetab_a - 1)
	{
		if (tmp > a[i])
			tmp = a[i];
		i++;
	}
	return (tmp);
}

int	check_tab(int *a, t_swap *swp)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j <= swp->sizetab_a - 1)
	{
		if (a[i] > a[j])
			return (1);
		i++;
		j++;
	}
	return (0);
}
