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

void	printerror(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

int	main(int ac, char **av)
{
    int *inttab;
    int i;
    t_node *temp;
    t_node *head;

    head = NULL;

	if (ac == 1)
		return (0);
	else
	{
        inttab = tabint (ac, av);
        if (!inttab)
            printerror();
        while (inttab[i])
        {
            temp = ft_node_create_new(inttab[i]);
            ft_node_insert_to_end(&head, temp);
            i++;

        }
        ft_node_print_list(head);
	}
}
