/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printorder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:24:23 by jroulet           #+#    #+#             */
/*   Updated: 2024/06/12 18:28:57 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
// return the max index in the linked list
int	findmaxindex(t_node *head)
{
	t_node	*current;
	int		max_index;

	current = head;
	if (current == NULL)
		return (0);
	max_index = current->index;
	if (current->next == NULL)
		return (max_index);
	while (current != NULL)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	return (max_index);
}

// return the node with the same index than input
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

// retunr the min index in the linked list
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
