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
	ft_printf("_______________FREETAB\n\n");
    int i = 0;

    if (tab == NULL) {
        return;
    }

    while (tab[i]) {
        free(tab[i]);
        i++;
    }

	ft_printf("\033[0;32mtab is being freed\033[0m\n");
    free(tab);
}

int	doublechecker(char **tab)
{
    ft_printf("DOUBLECHECKER\n\n");
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
            ft_printf("DB CHECK tab[%d] = %d tab[%d] = %d \n", i, ft_atoi(tab[i]), j - 1, ft_atoi(tab[j - 1]));
            if (ft_atoi(tab[i]) == ft_atoi(tab[j]))
			{
				ft_printf("\033[0;31mERROR DOUBLE\033[0m\n\n");
                return (0);
			}
            j--;
        }
        i++;
    }
	ft_printf("\033[0;32mOK DOUBLE\033[0m\n\n");
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
				ft_printf("\033[0;31mERROR ISINT\033[0m\n\n");
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


int	**tabint (int ac, char **av)
{
    ft_printf("_______________TABINT\n\n");
    char	**tab;
    int		i;

    ft_printf("ac = %d\n", ac);
    if (ac == 2)
    {
        tab = ft_split(av[1], ' ');
        i = 0;
        while (tab[i] != NULL)
        {
            ft_printf("split tab[%d] = %s\n", i, tab[i]);
            i++;
        }
    }
    else {
        tab = malloc(sizeof(char*) * (ac - 1));
        i = 0;
        while (i < ac - 1)
        {
            tab[i] = malloc(sizeof(char) * (ft_strlen(av[i + 1]) + 1));
            ft_strcpy(tab[i], av[i + 1]);
            ft_printf("tab[%d] = %s\n", i, tab[i]);
            i++;
        }
        tab[i] = NULL;
    }

    if (checker(tab, ac) == 0 || doublechecker(tab) == 0)
    {
        freetab(tab);
    }
    else
    {
        ft_printf("\033[0;32mALL INT\033[0m\n");
        freetab(tab);
    }
    return (NULL);
}
