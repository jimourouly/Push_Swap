/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinysort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:23:59 by jroulet           #+#    #+#             */
/*   Updated: 2024/06/19 14:11:54 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


// return a converted number in binary

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
	ft_node_print_list(*head, 'a');
	ft_node_print_list(*stackb, 'b');
	freelink(*head);

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
//sort a list of 3 elements

void	tinysort(t_node **head)
{
	t_node	*tmp;
	t_node	*a;
	t_node	*b;
	t_node	*c;

	tmp = *head;
	a = tmp;
	b = a->next;
	c = b->next;
	if (sortedlist(*head))
		return ;
	if (a->index < b->index)
	{
		if (a->index < c->index)
		{
			rra(head);
			sa(head);
		}
		else if (a->index > c->index)
			rra(head);
	}
	else
	{
		if (a->index < c->index)
			sa(head);
		else if (b->index < c->index)
			ra(head);
		else
		{
			sa(head);
			rra(head);
		}
	}
	tmp = *head;
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
