/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:23:59 by jroulet           #+#    #+#             */
/*   Updated: 2024/02/17 18:39:46 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <limits.h>

int	intchecker (char *number)
{
	int			i;
	int			k;
	long int	digit;

	digit = ft_atoli(number);
	if (digit < INT_MIN || digit > INT_MAX)
		printerror();
	i = 0;
	if (number[0] == '-' || number[0] == '+')
		i = 1;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			printerror();
		i++;
	}
	return (1);
}

void	printerror (void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	argtreat (int ac, char **av)
{
	char	**tab;
	int 	i;
	int		j;
	int		len;


	len = 0;
	i = i;	
	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		while (tab[len])
			len ++;
		ft_printf("len = %d\n", len);
		len --;
		j = len;
		ft_printf("j = :%d:\n", j);
		ft_printf("tab[%d] = :%s: \t tab[%d] = :%s:\n", i, tab[i], len, tab[len]);
		while (tab[i] != NULL)
		{
			intchecker(tab[i]);
			len = j;
			while (len > i)
			{
				if (ft_atoi(tab[i]) == ft_atoi(tab[len]))
					printerror();
				len --;
			}
			i++;
		}
		i = 0;
		while (tab[i])
		{
			ft_printf("free tab[%d]\n", i);
			free(tab[i]);
			free(*tab);
			i++;
		}
	}
	else
	{
		i = 1;
		while (i < ac)
		{
			len = ac -1;
			while (len > i)
			{
				if (ft_atoi(av[i]) == ft_atoi(av[len]))
					printerror();
				len --;
			}
			intchecker(av[i]);
			i++;
		}
		i = 1;
		while (i < ac)
		{
			free(*av);
		}
	}
}

int	main (int ac, char **av)
{
	int		i;
	char	**tab;

	i = 0;
	if (ac == 1)
		return (0);
	else
	{
		tabint (ac, av);
	//	argtreat (ac, av);
	}
	//ft_printf("tout INt gg bg\n");
	//lstcreator(ac, av);
}
