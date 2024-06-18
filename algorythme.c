/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:23:59 by jroulet           #+#    #+#             */
/*   Updated: 2024/06/12 18:28:20 by jroulet          ###   ########.fr       */
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
	size = ft_node_length(*head);
	pushb(&stacka, &stackb);
	if (size == 5)
	{
		pushb(&stacka, &stackb);
		if (!sortedlist(stackb))
			sb(&stackb);
	}
	tinysort(&stacka);
	while (size > 0 && stackb)
	{
		if (stackb->index == 1 && stackb)
		{
			pusha(&stacka, &stackb);
		}
		else if (stackb->index == 2 && stackb)
		{
			pusha(&stacka, &stackb);
			sa(&stacka);
		}
		else if (stackb->index == 3 && stackb)
		{
			ra(&stacka);
			ra(&stacka);
			pusha(&stacka, &stackb);
			rra(&stacka);
			rra(&stacka);
		}
		else if (stackb->index == 4 && stackb)
		{
			if (findmaxindex(stackb) == 4 && findmaxindex(stacka) != 5)
			{
				pusha(&stacka, &stackb);
				ra(&stacka);
			}
			else
			{
				rra(&stacka);
				pusha(&stacka, &stackb);
				if (findmaxindex(stackb) == 5)
					sa(&stacka);
				ra(&stacka);
				ra(&stacka);
			}
		}
		else if (stackb->index == 5 && stackb)
		{
			pusha(&stacka, &stackb);
			ra(&stacka);
		}
	}
}
