/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:04:40 by jroulet           #+#    #+#             */
/*   Updated: 2024/06/09 13:17:07 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rev(t_node **stack)
{
	t_node	*last;
	t_node	*prev;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	last->next = *stack;
	*stack = last;
	if (prev)
		prev->next = NULL;
}

void	rra(t_node **stacka)
{
	ft_printf("rra\n");
	rev(stacka);
}

void	rrb(t_node **stackb)
{
	ft_printf("rrb\n");
	rev(stackb);
}

void	rrr(t_node **stacka, t_node **stackb)
{
	ft_printf("rrr\n");
	rev(stacka);
	rev(stackb);
}
