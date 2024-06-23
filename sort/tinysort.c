/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinysort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:23:59 by jroulet           #+#    #+#             */
/*   Updated: 2024/06/23 11:27:02 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// push the node to stack b if the bit is 1, else rotate the node

void	push_to_stackb(t_node **head, t_node **stackb, int size, int i)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if ((((*head)->index >> i) & 1) == 1)
			ra(head);
		else
			pushb(head, stackb);
		j++;
	}
}
// do the sorting using radix sort

void	radix(t_node **head, t_node **stackb)
{
	int		maxindex;
	int		bit;
	int		i;
	int		size;

	maxindex = findmaxindex(*head);
	bit = ft_log(maxindex, 2) + 1;
	i = 0;
	while (i < bit)
	{
		size = ft_node_length(*head);
		push_to_stackb(head, stackb, size, i);
		while (*stackb)
			pusha(head, stackb);
		i++;
	}
}

//return a node by it's value

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
// add index from 1 to x to the list

void	simplifier(t_node *head)
{
	t_node	*current;
	int		max;
	int		counter;
	int		index;

	counter = findminnode(head)->value;
	max = findmaxnode(head)->value;
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

void	sort_three(t_node **head, int a_index, int b_index, int c_index)
{
	if (a_index < b_index)
	{
		if (a_index > c_index)
			rra(head);
		else if (b_index > c_index)
		{
			rra(head);
			sa(head);
		}
	}
	else
	{
		if (a_index < c_index)
			sa(head);
		else if (b_index < c_index)
			ra(head);
		else
		{
			sa(head);
			rra(head);
		}
	}
}

void	tinysort(t_node **head)
{
	t_node	*a;
	t_node	*b;
	t_node	*c;

	if (sortedlist(*head))
		return ;
	a = *head;
	b = a->next;
	c = b->next;
	sort_three(head, a->index, b->index, c->index);
}
//return the node with the max value in the list

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
//return the node with the min value in the list

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
//return 1 if the list is sorted, else 0

int	sortedlist(t_node *head)
{
	t_node	*current;

	current = head;
	while (current && current->next != NULL)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
