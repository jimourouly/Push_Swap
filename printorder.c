/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printorder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:24:23 by jroulet           #+#    #+#             */
/*   Updated: 2024/04/05 17:09:41 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	print_list_by_index(t_node *head)
{
	t_node	*current;
	int		min_index;
	int		max_index;
	int		index;

	min_index = findminindex(head);
	max_index = findmaxindex(head);
	index = min_index;
	while (index <= max_index)
	{
		current = findnodebyindex(head, index);
		if (current != NULL)
		{
			printf("Value: %d, Index: %d\n", current->value, current->index);
		}
		index++;
	}
}

int	findminindex(t_node *head)
{
	t_node	*current;
	int		min_index;

	current = head;
	min_index = current->index;
	while (current != NULL)
	{
		if (current->index < min_index)
			min_index = current->index;
		current = current->next;
	}

	return (min_index);
}

int	findmaxindex(t_node *head)
{
	t_node	*current;
	int		max_index;

	current = head;
	max_index = current->index;
	while (current != NULL)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}

	return (max_index);
}

t_node	*findnodebyindex(t_node *head, int index)
{
	t_node	*current;

	current = head;
	while (current != NULL)
	{
		if (current->index == index)
			return (current);
		current = current->next;
	}
	return (NULL);
}
