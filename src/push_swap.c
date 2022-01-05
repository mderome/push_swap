/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:12:03 by mderome           #+#    #+#             */
/*   Updated: 2022/01/03 10:44:22 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_all(char **arg, int ac)
{
	int		i;
	char	**test;
	int		ret;

	i = 1;
	ret = 0;
	while (arg[i] != NULL && i < ac - 1)
	{
		test = ft_split(arg[i], ' ');
		if (tab_len(test) != 1 && ac > 2)
		{
			ft_free(test);
			return (1);
		}
		ft_free(test);
		i++;
	}
	ret += check_all_2(arg, ac);
	return (ret);
}

void	init_swp(t_swap *swp)
{
	swp->sizetab = 0;
	swp->sizetab_a = 0;
	swp->sizetab_b = 0;
	swp->min = 0;
	swp->nb = 0;
}

int	check_arg(long int *tab_int, t_swap *swp)
{
	int	i;
	int	j;

	i = 0;
	while (i < swp->sizetab)
	{
		if ((long)tab_int[i] < INT_MIN || (long)tab_int[i] > INT_MAX)
			return (0);
		j = i + 1;
		while (j < swp->sizetab)
		{
			if (tab_int[i] == tab_int[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**make_tab(int argc, char **argv)
{
	int		i;
	int		j;
	char	**tab;

	j = 0;
	i = 1;
	tab = (char **)malloc(sizeof(char *) * argc);
	if (!tab)
		return (NULL);
	while (i < argc)
	{
		tab[j] = malloc(sizeof(char *) * (ft_strlen(argv[i]) + 1));
		ft_strlcpy(tab[j], argv[i], ft_strlen(argv[i]) + 1);
		i++;
		j++;
	}
	tab[j] = 0;
	return (tab);
}

int	main(int argc, char **argv)
{
	char		**tab;
	long int	*tab_int;
	t_swap		swp;

	init_swp(&swp);
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		tab_int = itoa_tab(tab, &swp);
	}
	else
	{
		tab = make_tab(argc, argv);
		tab[argc - 1] = NULL;
		tab_int = itoa_tab(tab, &swp);
	}
	if (check_arg(tab_int, &swp) == 0 || check_all(argv, argc) != 0)
	{
		free(tab_int);
		write(2, "Error\n", 6);
		return (0);
	}
	algo_choice(tab_int, &swp);
	free(tab_int);
	return (0);
}
