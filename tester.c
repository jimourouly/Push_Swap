/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:17:21 by jroulet           #+#    #+#             */
/*   Updated: 2024/02/24 17:17:25 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void run_tests(void)
{
    
    char *single_arg_tests[] = {
        "8 7 6",
        "8 7 6 k",
        "8 7 6 7",
        "8 7 6 99999999999",
    };
    int num_single_arg_tests = sizeof(single_arg_tests) / sizeof(single_arg_tests[0]);

    for (int i = 0; i < num_single_arg_tests; i++) {
        char *av[] = {single_arg_tests[i] };
        int ac = sizeof(av) / sizeof(av[0]);

        printf("\n\nTesting with single argument: '%s'\n", single_arg_tests[i]);
        tabint(ac, av);
    }

    char *multi_arg_tests[][5] = {
        {  "8", "7", "6", NULL },
        {  "8", "7", "6", "k", NULL },
        {  "8", "7", "6", "7", NULL },
        {  "8", "7", "6", "99999999999", NULL },
   
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

        tabint(ac, multi_arg_tests[i]);
    }
}