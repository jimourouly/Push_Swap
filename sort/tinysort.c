/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinysort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:23:59 by jroulet           #+#    #+#             */
/*   Updated: 2024/04/03 15:00:13 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	simplifier(t_node *head)
{
	t_node	*current;
	t_node	*temp;
	int		index;

	index = 0;
	findminnode(head, &index);
	findmaxnode(head);
	ft_printf("simpl\n\n");
	current = head;
}

void	tinysort(t_node *head)
{
	t_node	*current;
	t_node	*smallest;
	t_node	*biggest;

	ft_printf("tinysort\n");
	smallest = NULL;
	biggest = NULL;
	simplifier(head);
	ft_node_print_list(head);
}


t_node	*findmaxnode(t_node *head)
{
	t_node	*current;
	t_node	*biggest;

	ft_printf("findmax\n");
	current = head;
	biggest = head;
	while (current)
	{
		if (current->value > biggest->value)
			biggest = current;
		current = current->next;
	}
	ft_printf("max node = :%d:\n\n", biggest->value);
	ft_printf("max node val 2= :%d:\n\n", biggest->value2);
	return (biggest);
}

t_node	*findminnode(t_node *head, int *index)
{
	t_node	*current;
	t_node	*smallest;

	ft_printf("findmin\n");
	current = head;
	smallest = head;
	while (current)
	{
		if (current->value < smallest->value && current->value2 == 0)
		{
			smallest = current;
			smallest->index = *index;
			*index++;
		}
		current = current->next;
	}
	ft_printf("min node = :%d:\n\n", smallest->value);
	ft_printf("min node val 2= :%d:\n\n", smallest->value2);
	return (smallest);
}

int	sortedlist(t_node *head)
{
	t_node	*current;
	int		sorted;

	current = head;
	sorted = 1;
	while (current != NULL && current->next != NULL)
	{
		if (current->value > current->next->value)
			sorted = 0;
		current = current->next;
	}
	return (sorted);
}
