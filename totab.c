/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   totab.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:05:11 by jroulet           #+#    #+#             */
/*   Updated: 2024/02/23 14:37:01 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void freetab(char **tab)
{
    int i = 0;

    if (tab == NULL) {
        return;
    }

    while (tab[i]) {
        free(tab[i]);
        i++;
    }

    free(tab);
}

int	doublechecker(char **tab)
{
    ft_printf("DOUBLECHECKER\n");
    int i;
    int j;
    int len;

	i = 0;
	len = 0;
    while (tab[len])
        len++;

    while (i < len)
    {
        j = len - 1;
        while (j > i)
        {
            ft_printf("DB CHECK tab[%d] = %s tab[%d] = %s \n", i, tab[i], j, tab[j]);
            if (ft_atoi(tab[i]) == ft_atoi(tab[j]))
                return (0);
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
	//tab[i] = NULL;
	return (1);
}

int	**tabint (int ac, char **av)
{
	ft_printf("_______________TABINT\n\n");
	char	**tab;
	int		i;
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
	i = 1;
	while (i < ac)
	{
    	tab[i - 1] = malloc(sizeof(char) * (ft_strlen(av[i]) + 1));
    	ft_memcpy(tab[i - 1], av[i], ft_strlen(av[i]) + 1);
    	ft_printf("ac = %d tab[%d] = %s ptr = %p \n", ac, i - 1, tab[i - 1], &tab[i - 1]);
    	i++;
	}
	}
	if (checker(tab, ac) == 0 || doublechecker(tab) == 0)
	{
		ft_printf("errorsalut");
		freetab(tab);
	}
	else
	{
		ft_printf("ALL INT\n");
		freetab(tab);
	}
	return (NULL);
}
