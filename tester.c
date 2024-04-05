/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:17:21 by jroulet           #+#    #+#             */
/*   Updated: 2024/04/05 16:48:16 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void run_tests(void)
{
	int i;

	char *single_arg_tests[] = {
		"8 7 6",
		"8 7 6 k",
		"8 7 6 7",
		"8 7 6 99999999999",
		"k 7 6",
		"8 7 8",
		"8 k 7",
		"999999999999 8 7",
		"8 99999999999 8",
	};
	int num_single_arg_tests = sizeof(single_arg_tests) / sizeof(single_arg_tests[0]);

	for (int i = 0; i < num_single_arg_tests; i++) {
		char *av[] = {single_arg_tests[i] };
	int ac = sizeof(av) / sizeof(av[0]);

		printf("\n\nTesting with single argument: '%s'\n", single_arg_tests[i]);
		tabint(ac, av, &i);
	}

	char *multi_arg_tests[][5] = {
		{  "8", "7", "6", NULL },
		{  "8", "7", "6", "k", NULL },
		{  "8", "7", "6", "7", NULL },
		{  "8", "7", "6", "99999999999", NULL },
		{  "k", "7", "6", "8", NULL },
		{  "7", "k", "6", "8", NULL },
		{  "6", "7", "k", "8", NULL },
		{  "99999999999", "7", "9", "8", NULL },

	};

	int num_multi_arg_tests = sizeof(multi_arg_tests) / sizeof(multi_arg_tests[0]);

	for (int i = 0; i < num_multi_arg_tests; i++) {
		int ac = 0;
		while (multi_arg_tests[i][ac] != NULL) {
			ac++;
		}

		printf("\n\nTesting with multiple arguments: ");
		for (int j = 1; j < ac; j++) {
			printf("'%s' ", multi_arg_tests[i][j]);
		}
		printf("\n");

		tabint(ac, multi_arg_tests[i], &i);
	}
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
	freelink(stackA);
	freelink(stackB);
}
