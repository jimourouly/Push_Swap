/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:23:59 by jroulet           #+#    #+#             */
/*   Updated: 2024/02/10 20:42:04 by jroulet          ###   ########.fr       */
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
		i++;
	}
	return (1);
}

void printerror(void)
{
	ft_putstr_fd("Error\n", 2);
	return ;
}

int main (int ac, char **av)
{
	int	i;
	int	digit;

	i = 0;
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		// need to split into sll
	}
	else
	{
		i = 1;
		while (i < ac)
		{
			digit = intchecker(av[i]);
			if (digit == 0)
			{
				printerror();
				return (0);
			}

			i++;
		}
	}
}


