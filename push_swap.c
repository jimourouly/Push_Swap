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

void test_operations()
{
    int valuesA[] = {1, 2, 3};
    int valuesB[] = {4, 5, 6};
    int lenA = sizeof(valuesA) / sizeof(valuesA[0]);
    int lenB = sizeof(valuesB) / sizeof(valuesB[0]);
    t_node *stackA = NULL;
    t_node *stackB = NULL;
    t_node *temp;

    // Create stack A
    for (int i = 0; i < lenA; i++)
    {
        temp = ft_node_create_new(valuesA[i]);
        temp->next = NULL;
        ft_node_insert_to_end(&stackA, temp);
    }

    // Create stack B
    for (int i = 0; i < lenB; i++)
    {
        temp = ft_node_create_new(valuesB[i]);
        temp->next = NULL;
        ft_node_insert_to_end(&stackB, temp);
    }

    // Print the initial lists
    printf("Initial stack A: ");
    ft_node_print_list(stackA);
    printf("Initial stack B: ");
    ft_node_print_list(stackB);

    // Test pusha
    pushb(&stackA, &stackB);
    printf("After pusha: ");
    printf("Stack A: ");
    ft_node_print_list(stackA);
    printf("Stack B: ");
    ft_node_print_list(stackB);

    // Continue with other tests as needed...
}


int	main(int ac, char **av)
{
    int *inttab;
    int i;
    t_node *temp;
    t_node *head;
    int len;

    head = NULL;
	if (ac == 1)
    {
        test_operations();
        return (0);
    }
	else
    {
        inttab = tabint (ac, av, &len);
        if (!inttab)
            printerror();
        i = 0;
        while (i < len)
        {
            temp = ft_node_create_new(inttab[i]);
            temp->next = NULL;
            ft_node_insert_to_end(&head, temp);
            i++;
        }
        ft_node_print_list(head);
         
	}
}
