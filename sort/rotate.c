/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:04:47 by jroulet           #+#    #+#             */
/*   Updated: 2024/05/25 11:56:01 by jroulet          ###   ########.fr       */
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
	//ft_node_print_list(*stacka, 'a');

}

//ascending all nodes in stack b
void	rb(t_node **stackb)
{
	rotate(stackb);
	ft_printf("rb\n");
	//ft_node_print_list(*stackb, 'b');
}

//ascending all nodes in both stack
void	rr(t_node **stacka, t_node **stackb)
{
	ra(stacka);
	rb(stackb);
	ft_printf("rr\n");
}

/*

98 87 99 90
ra
87 99 90 98
pb
99 90 98      87
ra
90 98 99      87
pb
87 90 98 99
rra
99 87 90 98



*/
