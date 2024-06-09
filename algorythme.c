/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:23:59 by jroulet           #+#    #+#             */
/*   Updated: 2024/06/09 17:53:34 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	bigsort(t_node *head, t_node *stackb)
{
	simplifier(head);
	radix(&head, &stackb);
}

// free the linked list
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

// return a node at input index
t_node	*get_node_at_index(t_node *head, int index)
{
	t_node	*current;
	int		i;

	current = head;
	i = 0;
	while (i < index)
	{
		current = current->next;
		if (current == head)
			return (NULL);
		i++;
	}
	return (current);
}


// sort the linked list of 5 nodes - stacka
void	sortfive(t_node **head)
{
	t_node	*stacka;
	t_node	*stackb;
	int		size;

	stackb = NULL;
	stacka = *head;
	simplifier(stacka);
	size = ft_node_length(stacka);
	pushb(&stacka, &stackb);
	if (size == 5)
	{
		pushb(&stacka, &stackb);
		if (!sortedlist(stackb))
			sb(&stackb);
	}
	tinysort(&stacka);

	

	freelink(stacka);
	freelink(stackb);
}
