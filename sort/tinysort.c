/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinysort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:23:59 by jroulet           #+#    #+#             */
/*   Updated: 2024/03/25 13:30:21 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_extreme_nodes(t_node *head, t_node **smallest, t_node **biggest);

void	tinysort(t_node *head)
{
	t_node	*current;
	t_node	*smallest;
	t_node	*biggest;

	smallest = NULL;
	biggest = NULL;
	find_extreme_nodes(head, &smallest, &biggest);
}

void	find_extreme_nodes(t_node *head, t_node **smallest, t_node **biggest)
{
	t_node	*current;

	current = head;
	*smallest = head;
	*biggest = head;
	while (current != NULL)
	{
		if (current->value < (*smallest)->value)
		{
			*smallest = current;
		}
		if (current->value > (*biggest)->value)
		{
			*biggest = current;
		}
		current = current->next;
	}
	ft_printf("Smallest value: %d\n", (*smallest)->value);
	ft_printf("Biggest value: %d\n", (*biggest)->value);
}
