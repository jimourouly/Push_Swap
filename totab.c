/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   totab.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:05:11 by jroulet           #+#    #+#             */
/*   Updated: 2024/03/25 16:31:57 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*tabtoint(char **chartab)
{
	int	i;
	int	*inttab;

	i = 0;
	while (chartab[i])
	{
		i++;
		inttab = malloc(sizeof(int) * i);
	}
	i = 0;
	while (chartab[i])
	{
		inttab[i] = ft_atoi(chartab[i]);
		i++;
	}
	return (inttab);
}

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
			//ft_printf("\033[0;32mChecking double tab[%d] %d and tab[%d] %d\033[0m\n", i , ft_atoi(tab[i]), j, ft_atoi(tab[j]));
			if (ft_atoi(tab[i]) == ft_atoi(tab[j]))
			{
				//ft_printf("\033[0;31mtab[%d] :%d: = tab[%d] :%d:\033[0m\n", i, ft_atoi(tab[i]), j, ft_atoi(tab[j]));
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

int	checker(char **tab)
{
	int			i;
	int			j;
	long int	digit;

	i = 0;
	while (tab[i])
	{
		//ft_printf("\033[0;32mchecking chartab[%d] = %s\033[0m\n", i, tab[i]);
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '-' || tab[i][j] == '+')
			{
				j++;
				//ft_printf("\033[0;32mchecking chartab[%d][%d] = %c\033[0m\n", i, j, tab[i][j]);
			}
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

int	*tabint(int ac, char **av, int *len)
{
	char	**tab;
	int		i;
	int		dcheck;
	int		check;
	int		*inttab;

	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		i = 0;
		while (tab[i])
			i++;
	}
	else
	{
		tab = malloc(sizeof(char *) * (ac + 1));
		if (!tab)
		{
			freetab(tab,ac);
			return (NULL);
		}
		i = 0;
		while (i < ac - 1)
		{
			tab[i] = malloc(sizeof(char) * (ft_strlen(av[i + 1]) + 1));
			ft_strcpy(tab[i], av[i + 1]);
			//ft_printf("\033[0;32mcopy av[%d] = %s to tab[%d] = %s\033[0m\n", i + 1, av[i + 1], i, tab[i]);
			i++;
		}
		tab[i] = NULL;
	}
	if (tab == NULL)
	{
		ft_printf("\033[0;31mERROR MALLOC\033[0m\n");
		freetab(tab,ac);
		return (NULL);
	}
	if (checker(tab) == 0 || doublechecker(tab) == 0)
	{
		freetab(tab, ac);
		return (NULL);
	}
	else
	{
		inttab = (tabtoint(tab));
		*len = i;
		freetab(tab, ac);
		return (inttab);
	}
	freetab(tab, ac);
	return (NULL);
}
