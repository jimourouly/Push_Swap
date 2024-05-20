/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:23:59 by jroulet           #+#    #+#             */
/*   Updated: 2024/05/20 18:15:28 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	bigsort(t_node *head)
{
	t_node	*current;
	t_node	*smallest;
	t_node	*biggest;

	smallest = NULL;
	biggest = NULL;
	simplifier(head);
	getmaxbit(head);
}

void	freelink(t_node *head)
{
	t_node	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	sortfive(t_node *head)
{
	t_node	*stackb;
	t_node	*stacka;

	stackb = NULL;
	stacka = head;
	ft_node_print_list(stacka, 'a');
	ft_node_print_list(stackb, 'b');

	pushb(&stacka, &stackb);
	pushb(&stacka, &stackb);
	tinysort(stacka);


	ft_printf("____\n");
	ft_node_print_list(stacka, 'b');
	ft_node_print_list(stackb, 'b');
}
/*
void sortfive(t_node *head) {
    t_node *stackb;
    t_node *stacka;

    stackb = NULL;
    stacka = head;
    ft_node_print_list(stacka, 'a');
    ft_node_print_list(stackb, 'b');

    pushb(&stacka, &stackb);
    pushb(&stacka, &stackb);
    tinysort(&stacka);  // Pass by reference

    ft_printf("____\n");
    ft_node_print_list(stacka, 'a');
    ft_node_print_list(stackb, 'b');
}
*/
