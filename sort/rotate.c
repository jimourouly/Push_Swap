/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:04:47 by jroulet           #+#    #+#             */
/*   Updated: 2024/05/20 16:45:49 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_node **head)
{
	t_node	*tmp;
	t_node	*bottom;

	if (!head || !(*head)->next)
		return ;
	tmp = *head;
	*head = (*head)->next;
	bottom = getbottomnode(*head);
	tmp->next = NULL;
	bottom->next = tmp;
}

//ascending all nodes in stack a
void	ra(t_node **stacka)
{
	rotate(stacka);
	ft_printf("ra\n");
	ft_node_print_list(*stacka, 'a');

}

//ascending all nodes in stack b
void	rb(t_node **stackb)
{
	rotate(stackb);
	ft_printf("rb\n");
	ft_node_print_list(*stackb, 'b');
}

//ascending all nodes in both stack
void	rr(t_node **stacka, t_node **stackb)
{
	ra(stacka);
	rb(stackb);
	ft_printf("rr\n");
}
/*
30 20 10 SA RRA
30 10 20 RA
20 10 30 SA
20 30 10 RRA
10 30 20 RRA SA
10 20 30 sorted
*/
