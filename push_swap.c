/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:23:59 by jroulet           #+#    #+#             */
/*   Updated: 2024/02/11 14:09:21 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <limits.h>




int intchecker(char *number)
{
	int			i;
	int			num;
	long int 	digit;

	digit = ft_atoli(number);
	if (digit < INT_MIN || digit > INT_MAX)
		printerror();
	i = 0;
	if (number[0] == '-')
		i = 1;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
				printerror();
		i++;
	}
	ft_printf("char %s\n", number);
	printf("int %ld \n", digit);

	return (1);

}

void printerror(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0) ;
}

int main (int ac, char **av)
{
	int	i;
	char **tab;

	i = 0;
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		while(tab[i])
		{
			if(intchecker(tab[i]) == 0)
				printerror();
			i++;
		}
	}
	else
	{
		i = 1;
		while (i < ac)
		{
			if ((intchecker(av[i])) == 0)
				printerror();
			i++;
		}
	}
}


