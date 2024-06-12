/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:23:59 by jroulet           #+#    #+#             */
/*   Updated: 2024/06/12 17:55:05 by jroulet          ###   ########.fr       */
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
}


// sort the linked list of 5 nodes - stacka
void sortfive(t_node **head)
	{
		t_node	*stacka;
		t_node *stackb;
		int		size;

		stackb = NULL;
		stacka = *head;
		size = ft_node_length(*head);
		//ft_node_print_list(stacka, 'a');
		pushb(&stacka, &stackb);
		if (size == 5)
		{
			pushb(&stacka, &stackb);
			if (!sortedlist(stackb))
				sb(&stackb);
		}
	//	ft_node_print_list(stacka, 'a');
	//	ft_node_print_list(stackb, 'b');
		tinysort(&stacka);
	//	ft_node_print_list(stacka, 'a');
	//	ft_node_print_list(stackb, 'b');


		while (size > 0 && stackb)
		{
			if (stackb->index == 1 && stackb)
			{
			//ft_printf("\t1\n");
			//	ft_printf("stackb->index :%d:\n", stackb->index);
				pusha(&stacka, &stackb);
			}
			else if (stackb->index == 2 && stackb)
			{
			//ft_printf("stackb->index :%d:\n", stackb->index);
				//ft_printf("\t2\n");
				pusha(&stacka, &stackb);
				sa(&stacka);
			}
			else if (stackb->index == 3 && stackb)
			{
			//	ft_printf("stackb->index :%d:\n", stackb->index);
			//	ft_printf("\t3\n");
				ra(&stacka);
				ra(&stacka);
				pusha(&stacka, &stackb);
				rra(&stacka);
				rra(&stacka);
			}
			else if (stackb->index == 4 && stackb)
			{

			//	ft_printf("\t4\n");
				if (findmaxindex(stackb) == 4 && findmaxindex(stacka) != 5)
				{
				//	ft_printf("maxindex :%d:\n", findmaxindex(stackb));
					pusha(&stacka, &stackb);
					ra(&stacka);
				}
				else
				{
				//	ft_node_print_list(stacka, 'a');
				//	ft_node_print_list(stackb, 'b');
					rra(&stacka);
					pusha(&stacka, &stackb);

			//	ft_printf("maxindex :%d:\n", findmaxindex(stackb));
					if (findmaxindex(stackb)== 5)
						sa(&stacka);
					ra(&stacka);
					ra(&stacka);
				}
			}
			else if (stackb->index == 5 &&stackb)
			{
			//	ft_printf("stackb->index :%d:\n", stackb->index);
			//	ft_printf("\t5\n");
				pusha(&stacka, &stackb);
				ra(&stacka);
			}
		}
	//ft_node_print_list(stacka, 'a');
		freelink(stackb);
		freelink(stacka);
	}
