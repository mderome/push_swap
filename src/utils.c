/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:05:33 by mderome           #+#    #+#             */
/*   Updated: 2022/01/03 10:38:00 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

void	ft_free_tab(int *tab)
{
	free(tab);
	tab = NULL;
}

void	ft_free_tab_int(long int *tab, t_swap *swp)
{
	int	i;

	i = 0;
	while (i < swp->sizetab_a)
	{
		free((void *)tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

void	rotate_b_and_write(int *b, t_swap *swp)
{
	rotate_b(b, swp);
	write(1, "rb\n", 3);
}

void	init_pos(t_pos *pos)
{
	pos->nb = 0;
	pos->revers_a = 0;
	pos->revers_b = 0;
	pos->count = 0;
	pos->moov_a = 0;
	pos->moov_b = 0;
}
