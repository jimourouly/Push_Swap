/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:23:59 by jroulet           #+#    #+#             */
/*   Updated: 2024/06/10 18:57:48 by jroulet          ###   ########.fr       */
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
void	ft_node_print_list(t_node *head, char stack)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = head;
	if (stack == 'a')
	{
		while (temp != NULL)
		{
			//ft_printf("\033[0;34mstack%c [%d] value :%d: index :%d: indexbin :%d:\033[0m\n",stack, i, temp->value, temp->index, ft_inttobin(temp->index));
			ft_printf("\033[0;34mstack%c value :%d: index :%d: indexbin :%d:\033[0m\n",stack,  temp->value, temp->index, temp->index);
			temp = temp->next;
			i++;
		}
	}
	else
	{
		while (temp != NULL)
		{
			//ft_printf("\033[0;32mstack%c [%d] value :%d: index :%d: indexbin :%d: \033[0m\n",stack, i, temp->value, temp->index, ft_inttobin(temp->index));
			ft_printf("\033[0;32mstack%c value :%d: index :%d: indexbin :%d: \033[0m\n",stack, temp->value, temp->index, temp->index);
			temp = temp->next;
			i++;
		}
	}
	ft_printf("\n");
	//ft_printf("\n");
}
/*void handle_stackb1(t_node *stacka, t_node *stackb)
{
	t_node *tmp;
	t_node *tmp2;

	tmp = stacka;
	tmp2 = stackb;

	ft_printf("handle_stackb1\n");
	ft_printf("stackb->index = %d\n", stackb->index);
	while (tmp)
	{
		ft_printf("stacka->index = %d\n", tmp->index);
		tmp = tmp->next;
	}
}

void handle_stackb2(t_node *stacka, t_node *stackb)
{
	t_node *tmp;
	t_node *tmp2;

	ft_printf("handle_stackb2\n");
	tmp = stacka;
	tmp2 = stackb;

}*/

// sort the linked list of 5 nodes - stacka
void sortfive(t_node **head)
	{
		t_node *stacka;
		t_node *stackb;

		int size;

		stackb = NULL;
		stacka = *head;

		simplifier(stacka);
		size = ft_node_length(*head);
		pushb(&stacka, &stackb);
		if (size == 5)
		{
			pushb(&stacka, &stackb);
			if (!sortedlist(stackb))
				sb(&stackb);
		}
		ft_node_print_list(stacka, 'a');
		ft_node_print_list(stackb, 'b');
		//tinysort(&stacka);

		/*if (size == 4)
			handle_stackb1(stacka, stackb);
		else
			handle_stackb2(stacka, stackb);
*/
		ft_node_print_list(stacka, 'a');
		ft_node_print_list(stackb, 'b');
		freelink(stacka);
		freelink(stackb);
	}
