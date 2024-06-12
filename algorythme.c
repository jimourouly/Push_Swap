/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:23:59 by jroulet           #+#    #+#             */
/*   Updated: 2024/06/12 15:09:13 by jroulet          ###   ########.fr       */
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


// sort the linked list of 5 nodes - stacka
void sortfive(t_node **head)
	{
		t_node *a;
		t_node *b;
		t_node *c;
		t_node *d;
		t_node *stackb;
		int		size;

		stackb = NULL;
		a = *head;
		b = a->next;
		c = b->next;
		d = c->next;

		simplifier(a);
		size = ft_node_length(*head);
		pushb(&a, &stackb);
		if (size == 5)
		{
			pushb(&a, &stackb);
			if (!sortedlist(stackb))
				sb(&stackb);
		}
		tinysort(&a);
		//ft_node_print_list(a, 'a');
		//ft_node_print_list(stackb, 'b');
		//ft_printf("size :%d:\n", size);

		while (size > 0 && stackb)
		{
			//ft_printf("while\n");
			//ft_node_print_list(a, 'a');
			//ft_node_print_list(stackb, 'b');
			if (stackb->value < a->value)
			{

			//	ft_printf("1\n");
				pusha(&a, &stackb);
			}
			else if (stackb->value < b->value)
			{

			//	ft_printf("2\n");
				pusha(&a, &stackb);
				sa(&a);
			}
			else if (stackb->value < c->value)
			{
				//ft_node_print_list(a, 'a');
			//	//ft_printf("3\n");
			//	ft_printf("stackb->value :%d:\n", stackb->value);
			//	ft_printf("a->value :%d:\n", a->value);
			//	ft_printf("c->value :%d:\n", c->value);
				pusha(&a, &stackb);
				sa(&a);

			}
			else if (stackb->value < d->value)
			{
			//	ft_printf("4\n");
				rra(&a);
				pusha(&a, &stackb);
				ra(&a);
				ra(&a);
			}
			else if (stackb->value > d->value)
			{
			//	ft_printf("5\n");
				pusha(&a, &stackb);
				ra(&a);

			}
			//ft_printf("endwhile\n");
			//ft_node_print_list(a, 'a');
			//ft_node_print_list(stackb, 'b');
		}
	//ft_node_print_list(a, 'a');

	}

	/*
	if ba < aa
		pusha
	if ba > aa && ba < ab
		pa
		sa
	if ba > aa && ba > ab && ba < ac
		ra
		ra
		pa
		rra
		rra
	if ba > aa && ba > ab && ba > ac && ba < ad
		rra
		pa
		ra
		ra
	if ba > aa && ba > ab && ba > ac && ba > ad
		pa
		rra


1 2 3 4 5
1 2 3 5 4
1 2 4 3 5
1 2 4 5 3
1 2 5 3 4
1 2 5 4 3
1 3 2 4 5
1 3 2 5 4
1 3 4 2 5
1 3 4 5 2
1 3 5 2 4
1 3 5 4 2
1 4 2 3 5
1 4 2 5 3
1 4 3 2 5
1 4 3 5 2
1 4 5 2 3
1 4 5 3 2
1 5 2 3 4
1 5 2 4 3
1 5 3 2 4
1 5 3 4 2
1 5 4 2 3
1 5 4 3 2
2 1 3 4 5
2 1 3 5 4
2 1 4 3 5
2 1 4 5 3
2 1 5 3 4
2 1 5 4 3
2 3 1 4 5
2 3 1 5 4
2 3 4 1 5
2 3 4 5 1
2 3 5 1 4
2 3 5 4 1
2 4 1 3 5
2 4 1 5 3
2 4 3 1 5
2 4 3 5 1
2 4 5 1 3
2 4 5 3 1
2 5 1 3 4
2 5 1 4 3
2 5 3 1 4
2 5 3 4 1
2 5 4 1 3
2 5 4 3 1
3 1 2 4 5
3 1 2 5 4
3 1 4 2 5
3 1 4 5 2
3 1 5 2 4
3 1 5 4 2
3 2 1 4 5
3 2 1 5 4
3 2 4 1 5
3 2 4 5 1
3 2 5 1 4
3 2 5 4 1
3 4 1 2 5
3 4 1 5 2
3 4 2 1 5
3 4 2 5 1
3 4 5 1 2
3 4 5 2 1
3 5 1 2 4
3 5 1 4 2
3 5 2 1 4
3 5 2 4 1
3 5 4 1 2
3 5 4 2 1
4 1 2 3 5
4 1 2 5 3
4 1 3 2 5
4 1 3 5 2
4 1 5 2 3
4 1 5 3 2
4 2 1 3 5
4 2 1 5 3
4 2 3 1 5
4 2 3 5 1
4 2 5 1 3
4 2 5 3 1
4 3 1 2 5
4 3 1 5 2
4 3 2 1 5
4 3 2 5 1
4 3 5 1 2
4 3 5 2 1
4 5 1 2 3
4 5 1 3 2
4 5 2 1 3
4 5 2 3 1
4 5 3 1 2
4 5 3 2 1
5 1 2 3 4
5 1 2 4 3
5 1 3 2 4
5 1 3 4 2
5 1 4 2 3
5 1 4 3 2
5 2 1 3 4
5 2 1 4 3
5 2 3 1 4
5 2 3 4 1
5 2 4 1 3
5 2 4 3 1
5 3 1 2 4
5 3 1 4 2
5 3 2 1 4
5 3 2 4 1
5 3 4 1 2
5 3 4 2 1
5 4 1 2 3
5 4 1 3 2
5 4 2 1 3
5 4 2 3 1
5 4 3 1 2
5 4 3 2 1
	*/
