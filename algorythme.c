/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:23:59 by jroulet           #+#    #+#             */
/*   Updated: 2024/05/25 14:47:30 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	bigsort(t_node *head)
{
	t_node	*current;
	t_node	*smallest;
	t_node	*biggest;

	smallest = NULL;
	biggest = NULL;
	simplifier(head);
	getmaxbit(head);
}

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

void	sortfive(t_node **head)
{
	ft_printf("sortfive\n");
	t_node	*stackb;
	t_node	*stacka;
	int		size;

	stackb = NULL;
	stacka = *head;
	simplifier(stacka);
	size = ft_node_length(stacka);
	ft_node_print_list(stacka, 'a');
	ft_node_print_list(stackb, 'b');

	pushb(&stacka, &stackb);
	if (size == 5)
		pushb(&stacka, &stackb);
	ft_node_print_list(stacka, 'a');
	ft_node_print_list(stackb, 'b');
	tinysort(&stacka);
	ft_node_print_list(stacka, 'a');
	ft_node_print_list(stackb, 'b');

	if (size == 5)
	{
		if ((stackb->index > stackb->next->index)&& size == 5)
			sb(&stackb);
	}
	ft_node_print_list(stacka, 'a');
	ft_node_print_list(stackb, 'b');

	//while (stackb)
	//{
		ft_printf("stackb->value = :%d: stacka->value = :%d:\n", stackb->value, stacka->value);
		if (stackb->value < stacka->value)
			pusha(&stacka, &stackb);

		if (findmaxnode(stackb)->value > findmaxnode(stacka)->value)
			ft_printf("BIG\n");
		ft_node_print_list(stacka, 'a');
		ft_node_print_list(stackb, 'b');
//	}
}
