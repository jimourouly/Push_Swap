/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   totab.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:05:11 by jroulet           #+#    #+#             */
/*   Updated: 2024/02/19 16:53:55 by jroulet          ###   ########.fr       */
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
	ft_printf("____________________CHECKER\n\n");
	int			i;
	int			j;
	long int	digit;

	i =0;
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
	ft_printf("_______________TABINT\n\n");
	char	**tab;
	int		i;
	int		check;

	ft_printf("ac = %d\n", ac);
	tab = malloc(sizeof(char*) * ac);
	i = 0;
	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		while (tab[i] != NULL)
		{
			ft_printf("split tab[%d] = %s\n", i, tab[i]);
			i++;
		}
	}
	else {
		while (i < ac)
		{
			tab[i] = malloc(sizeof(char*) * ft_strlen(av[i] + 1));
			tab[i] = av[i];
			ft_printf("ac = %d tab[%d] = %s\n", ac ,i, tab[i]);
			i++;
		}
	}
		check = checker(tab);
	if (check == 0)
	{
		i--;
		ft_printf("i = %d\n", i);
		while (i >= 0)
		{
			ft_printf("tab[%d] %s LIBERTE\n", i, tab[i]);
			//free(tab[i]);
			i -- ;
		}
		//free(tab);
	}
	ft_printf("is int = %d\n", check);
	return (NULL);
}
