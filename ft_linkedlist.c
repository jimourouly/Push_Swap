/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkedlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:50:16 by jroulet           #+#    #+#             */
/*   Updated: 2024/03/06 18:12:37 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*getbottomnode(t_node *stack)
{
	t_node	*tmp;

	if (!stack)
		return (NULL);
	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_node	*ft_node_create_new(int value)
{
	t_node	*result;

	result = malloc(sizeof(t_node));
	if (!result)
		return (NULL);
	result->value = value;
	result->next = NULL;
	return (result);
}

void	ft_node_insert_to_end(t_node **head, t_node *newnode)
{
	t_node	*current;

	if (*head == NULL)
	{
		*head = newnode;
	}
	else
	{
		current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newnode;
	}
}

int	ft_node_length(t_node *head)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = head;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	ft_node_print_list(t_node *head)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = head;
	while (temp != NULL)
	{
		ft_printf("\033[0;32mLinkedlist [%d] value :%d:\033[0m\n", i, temp->value);
		temp = temp->next;
		i++;
	}
	ft_printf("\n");
}


