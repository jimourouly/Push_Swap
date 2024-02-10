/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:23:59 by jroulet           #+#    #+#             */
/*   Updated: 2024/02/10 20:23:37 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int intchecker(char *number)
{
	int	i;

	i = 0 ;

	if (number[0] == '-')
		i = 1;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
				return (0);
	}
	return (1);
}


int main (int ac, char **av)
{
	int	i;
	int	digit;

	i = 0;
	if (ac == 1)
		return (0);
	else
	{
		i = 1;
		while (i < ac)
		{
			ft_printf("av[%d] = :%s:\n", i, av[i]);
			ft_printf("digit = %d\n", digit);
			digit = ft_atoi(av[i]);
			ft_printf("digit = :%d:\n", digit);
			digit = ft_isdigit(digit);
			ft_printf("digit = %d\n", digit);
			i++;
		}
	}
}


