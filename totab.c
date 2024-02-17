/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   totab.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:05:11 by jroulet           #+#    #+#             */
/*   Updated: 2024/02/17 20:01:37 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker (char **tab)
{
	ft_printf("CHECKER\n\n");
	int			i;
	int			j;
	long int	digit;

	i = 0;
	while (tab[i])
	{
		ft_printf("tab[%d] = %s \n",i, tab[i]);
		j = 0;
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j]))
			{
				ft_printf("pas int");
				return (0);
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (tab[i])
	{
		digit = (ft_atoli(tab[i]));
		if (digit < INT_MIN || digit > INT_MAX)
		{
			ft_printf("trop gros");
			return (0);
		}
		i++;
	}
	return (1);
}

int	**tabint (int ac, char **av)
{
	ft_printf("TABINT\n\n");
	char	**tab;
	int		i;
	int		check;
	int		**inttab;

	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
	}
	else
	{
		i = 1;
		tab = ft_calloc(ac + 1, sizeof(char *));
		while (i < ac)
		{
			tab[i - 1] = av[i];
			i++;
		}
	}
	//to delete later
	i = 0;
	while (tab[i])
		ft_printf("%s\n", tab[i++]);
	//to delete later
	check = checker(tab);
	ft_printf("is int = %d\n", check);
	return (*tab);
}
