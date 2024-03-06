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
    int valuesA[] = {10, 20, 30};
    int valuesB[] = {40, 50, 60};
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
    printf("Initial stack A: \n");
    ft_node_print_list(stackA);
    printf("Initial stack B: \n");
    ft_node_print_list(stackB);

    // Test pusha
    pusha(&stackA, &stackB);
    printf("Stack A: \n");
    ft_node_print_list(stackA);
    printf("Stack B: \n");
    ft_node_print_list(stackB);

   // Test pushb
    pushb(&stackA, &stackB);
    printf("Stack A: \n");
    ft_node_print_list(stackA);
    printf("Stack B: \n");
    ft_node_print_list(stackB);

    // Test sa
    sa(&stackA);
    printf("Stack A: \n");
    ft_node_print_list(stackA);

    // Test sb
    sb(&stackB);
    printf("Stack B: \n");
    ft_node_print_list(stackB);

    // Test ss
    ss(&stackA,&stackB);
    printf("Stack B: \n");
    ft_node_print_list(stackB);
    printf("Stack A: \n");
    ft_node_print_list(stackA);

    // Test rra
    rra(&stackA);
    printf("Stack A: \n");
    ft_node_print_list(stackA);

    // Test rrb
    rrb(&stackB);
    printf("Stack B: \n");
    ft_node_print_list(stackB);

    // Test rrr
    rrr(&stackA, &stackB);
    printf("Stack A: \n");
    ft_node_print_list(stackA);
    printf("Stack B: \n");
    ft_node_print_list(stackB);


    // Test rotate
    ra(&stackA);
    printf("Stack A: \n");
    ft_node_print_list(stackA);
    rb(&stackB);
    printf("Stack B: \n");
    ft_node_print_list(stackB);

    pusha(&stackA, &stackB);
    printf("Stack A: \n");
    ft_node_print_list(stackA);
    printf("Stack B: \n");
    ft_node_print_list(stackB);

    pusha(&stackA, &stackB);
    printf("Stack A: \n");
    ft_node_print_list(stackA);
    printf("Stack B: \n");
    ft_node_print_list(stackB);

    pusha(&stackA, &stackB);
    printf("Stack A: \n");
    ft_node_print_list(stackA);
    printf("Stack B: \n");
    ft_node_print_list(stackB);
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
