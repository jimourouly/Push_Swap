/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   totab.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:05:11 by jroulet           #+#    #+#             */
/*   Updated: 2024/02/17 21:51:24 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	doublechecker(char **tab)
{
	ft_printf("DOUBLECHECKER\n");
	int	i;
	int	j;
	int	len;

	len = 0;
	i = 0;
	while (tab[len])
		len ++;
		
	while (tab[i])
	{
		j = len - 1;
		while (j > i)
		{
			//ft_printf("tab[%d] = %s tab[%d] = %s \n",i, tab[i], j, tab[j] );
			if (ft_atoi(tab[i]) == ft_atoi(tab[j]))
				return (0);
			j--;
		}
		i++;
	}
	return (1);
}

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
			if (tab[i][j] == '-' || tab[i][j] == '+')
				j ++;
			if (!ft_isdigit(tab[i][j]))
			{
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
			return (0);
		}
		i++;
	}
	tab[i] = NULL;
	return (1);
}

int	**tabint (int ac, char **av)
{
	ft_printf("TABINT\n\n");
	char	**tab;
	int		i;
	int		check;

	i = 1;
	if (ac >= 2)
	{
		while (i <= ac)
		{
			tab = ft_split(av[1], ' ');
			i++;
		}
	}
	//to delete later
	i = 0 ;
	while (i < ac)
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
	//to delete later
	check = checker(tab);
	if (check == 0)
	{
		i --;
		while (i >= 0)
		{
			ft_printf("tab[%d] %s part pour la liberte\n", i, tab[i]);
			free(tab[i]);
			i -- ;
		}
		free(tab);
	}
	ft_printf("is int = %d\n", check);
	return (NULL);
}
