/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   totab.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:05:11 by jroulet           #+#    #+#             */
/*   Updated: 2024/02/24 17:43:51 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freetab(char **tab, int ac)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (tab[i])
		{
			ft_printf("\033[0;32mfree tab[%d] = %s\033[0m\n", i, tab[i]);
			free(tab[i]);
			i++;
		}
	}
	else
	{
		while (i < ac - 1)
		{
			ft_printf("\033[0;32mfree tab[%d] = %s\033[0m\n", i, tab[i]);
			free(tab[i]);
			i++;
		}
	}
	ft_printf("\033[0;32mfree tab\033[0m\n");
	free(tab);
}

int	doublechecker(char **tab)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (tab[len])
		len++;
	while (i < len)
	{
		j = len - 1;
		while (j > i)
		{
			if (ft_atoi(tab[i]) == ft_atoi(tab[j]))
			{
				ft_printf("\033[0;31mERROR DOUBLE\033[0m\n");
				return (0);
			}
			j--;
		}
		i++;
	}
	ft_printf("\033[0;32mOK DOUBLE\033[0m\n");
	return (1);
}

int	checker(char **tab, int ac)
{
	int			i;
	int			j;
	long int	digit;

	i = 1;
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
				ft_printf("\033[0;31mERROR ISINT\033[0m\n");
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
			ft_printf("\033[0;31mERROR TO BIG\033[0m\n");
			return (0);
		}
		i++;
	}
	ft_printf("\033[0;32mOK INT AND LIMIT INT\033[0m\n");
	return (1);
}

int	**tabint(int ac, char **av)
{
	char	**tab;
	int		i;
	int		dcheck;
	int		check;

	if (ac == 2)
		tab = ft_split(av[1], ' ');
	else
	{
		tab = malloc(sizeof(char *) * (ac - 1));
		i = 0;
		while (i < ac - 1)
		{
			tab[i] = malloc(sizeof(char) * (ft_strlen(av[i + 1]) + 1));
			ft_strcpy(tab[i], av[i + 1]);
			i++;
		}
		tab[i] = NULL;
	}
	if (tab == NULL)
	{
		ft_printf("\033[0;31mERROR MALLOC\033[0m\n");
		return (NULL);
	}
	if (checker(tab, ac) == 0 || doublechecker(tab) == 0)
	{
		freetab(tab, ac);
		return (NULL);
	}
	freetab(tab, ac);
	return (NULL);
}
