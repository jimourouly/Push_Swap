/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:04:40 by jroulet           #+#    #+#             */
/*   Updated: 2024/03/06 18:11:00 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rev(t_node **stack)
{
	t_node	*last;
	t_node	*justbeforethelast;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	justbeforethelast = NULL;
	while (last->next != NULL)
	{
		justbeforethelast = last;
		last = last->next;
	}

	justbeforethelast->next = NULL;
	last->next = *stack;
	*stack = last;
}

//descend all node from a
void	rra(t_node **stacka)
{
	rev(stacka);
	ft_printf("\033[0;31m RRA - all down on A\033[0m\n");
}

//descend all node from b
void	rrb(t_node **stackb)
{
	rev(stackb);
	ft_printf("\033[0;31m RRB - all down on B\033[0m\n");
}

//rra and rrb
void	rrr(t_node **stacka, t_node **stackb)
{
	rev(stacka);
	rev(stackb);
	ft_printf("\033[0;31m RRR - all down on A and B \033[0m\n");
}
