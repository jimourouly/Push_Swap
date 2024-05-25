/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinysort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:23:59 by jroulet           #+#    #+#             */
/*   Updated: 2024/05/25 17:54:44 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "math.h"

int	convert_to_binary(int num)
{
	int	binary;
	int	remainder;
	int	i;

	binary = 0;
	remainder = 1;
	i = 1;
	while (num != 0)
	{
		remainder = num % 2;
		num /= 2;
		binary += remainder * i;
		i *= 10;
	}
	return (binary);
}

void	radix(t_node **head, t_node **stackb)
{
	int		maxindex;
	int		bit;
	int		i;
	int		j;
	int		size;

	maxindex = findmaxindex(*head);
	bit = ft_log(maxindex, 2) + 1;
	i = 0;
	while (i < bit)
	{
		size = ft_node_length(*head);
		j = 0;
		while (j < size)
		{
			if ((((*head)->index >> i) & 1) == 1)
				ra(head);
			else
				pushb(head, stackb);
			j++;
		}
		while (*stackb)
			pusha(head, stackb);
		i++;
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
	radix(&head, &stackb);
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

void tinysort(t_node **head) {
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = *head;
	second = first->next;
	third = second->next;
	simplifier(*head);

	if (first->index < second->index)
	{
		rra(head);
		if (first->index < third->index)
			sa(head);
	}
	else if (second->index > third->index)
	{
		sa(head);
		rra(head);
	}
	else if (first->index < third->index)
		sa(head);
	else
		ra(head);
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

int sortedlist(t_node *head)
{
	t_node	*current;
	int		sorted;

	current = head;
	sorted = 1;
	while (current && current->next != NULL)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (sorted);
}

