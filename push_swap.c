/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:23:59 by jroulet           #+#    #+#             */
/*   Updated: 2024/02/24 17:20:12 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <limits.h>

int	intchecker(char *number)
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

void	printerror(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

int	main(int ac, char **av)
{
	run_tests();
	if (ac == 1)
		return (0);
	else
	{
		tabint (ac, av);
	}
}
