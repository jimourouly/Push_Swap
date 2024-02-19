/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   totab.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:05:11 by jroulet           #+#    #+#             */
/*   Updated: 2024/02/19 17:27:49 by jroulet          ###   ########.fr       */
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
			ft_printf("DB CHECK tab[%d] = %s tab[%d] = %s \n",i, tab[i], j, tab[j] );
			if (ft_atoi(tab[i]) == ft_atoi(tab[j]))
				return (ft_atoi(tab[i]));
			j--;
		}
		i++;
	}
	return (1);
}

int	checker (char **tab, int ac)
{
	ft_printf("____________________CHECKER\n\n");
	int			i;
	int			j;
	long int	digit;

	i =1;
	if (ac != 2)
		i++;
	while (tab[i])
	{
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
	int		j;

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
		i = 0;
		while (i < ac)
		{
			tab[i] = malloc(sizeof(char*) * ft_strlen(av[i] + 1));
			tab[i] = av[i];
			ft_printf("ac = %d tab[%d] = %s ptr = %p \n", ac ,i, tab[i], &tab[i]);
			i++;
		}
	}
	check = checker(tab, ac);
	check = doublechecker(tab);
	if (check != 0)
		ft_printf("DOUBL\n");
	if (check == 0)
	{
		i--;
		ft_printf("i = %d\n", i);
		if (ac !=2)
			j = 1;
		else
			j = 0;

		while (i >= j)
		{

			ft_printf("tab[%d] ptr[%p] %s LIBERTE\n", i, &tab[i], tab[i]);
			//free(tab[i]);
			i -- ;
		}
		free(tab);
	}
	ft_printf("is int = %d\n", check);
	return (NULL);
}
