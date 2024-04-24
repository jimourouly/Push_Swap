/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinysort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:23:59 by jroulet           #+#    #+#             */
/*   Updated: 2024/04/24 18:35:12 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "math.h"

void	radix(t_node *head,t_node *stackb)
{
	t_node	*current;
	t_node	*tempb;
	int		maxindex;
	int		bit;
	int		num;

	tempb = stackb;


	maxindex = findmaxindex(head);
	bit = (ft_log(maxindex, 2) + 1);
	ft_printf("bit = %d\n", bit);
	current = head;
	while (current)
	{
		num = current->index;
		ft_printf("if = %d\n", ((num >> (bit-1)) & 1));
		if (((num >> bit) & 1) == 1)
		{
			ft_printf("RA");
			ra(&head);
		}
		else
		{
			ft_printf("PUSHB");
			pushb(&head, &stackb);

		}
		current = current->next;
	}
	ft_node_print_list(head, 'a');
	ft_node_print_list(stackb, 'b');

	if (!sortedlist(head))
	{
		radix(head, stackb);
	}
}


void	getmaxbit(t_node *head)
{
	t_node	*current;
	t_node	*stackb;
	int		maxindex;
	int		log;
	int		base;

	stackb = NULL;
	current = head;
	maxindex = findmaxindex(head);
	log = ft_log(maxindex, 2);
	base = ft_log(maxindex, 2) + 1;
	ft_node_print_list(head, 'a');
	ft_node_print_list(stackb, 'b');
	radix(head, stackb);
}


t_node	*findnodebyvalue(t_node *head, int value)
{
	t_node	*current;

	current = head;
	while (current != NULL)
	{
		if (current->value == value)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	simplifier(t_node *head)
{
	t_node	*current;
	int		min;
	int		max;
	int		counter;
	int		index;

	min = findminnode(head)->value;
	max = findmaxnode(head)->value;
	counter = min;
	index = 1;
	while (counter <= max)
	{
		current = findnodebyvalue(head, counter);
		if (current != NULL)
		{
			current->index = index;
			index++;
		}
		counter++;
	}
}

void	tinysort(t_node *head)
{
	t_node	*current;
	t_node	*smallest;
	t_node	*biggest;
	t_node	*stackb;

	smallest = NULL;
	biggest = NULL;
	simplifier(head);
	getmaxbit(head);
}

t_node	*findmaxnode(t_node *head)
{
	t_node	*current;
	t_node	*biggest;

	current = head;
	biggest = head;
	while (current)
	{
		if (current->value > biggest->value)
			biggest = current;
		current = current->next;
	}
	return (biggest);
}

t_node	*findminnode(t_node *head)
{
	t_node	*current;
	t_node	*smallest;

	current = head;
	smallest = head;
	while (current)
	{
		if (current->value < smallest->value)
		{
			smallest = current;
		}
		current = current->next;
	}
	return (smallest);
}

int	sortedlist(t_node *head)
{
	t_node	*current;
	int		sorted;

	current = head;
	sorted = 1;
	while (current && current->next != NULL)
	{
		if (current->value > current->next->value)
			sorted = 0;
		current = current->next;
	}
	return (sorted);
}
