/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:04:40 by jroulet           #+#    #+#             */
/*   Updated: 2024/05/20 17:45:14 by jroulet          ###   ########.fr       */
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

//descend all node from a
void	rra(t_node **stacka)
{
	ft_printf("rra\n");
	ft_node_print_list(*stacka, 'a');
	rev(stacka);

	ft_printf("rra res\n");
	ft_node_print_list(*stacka, 'a');
}

//descend all node from b
void	rrb(t_node **stackb)
{

	ft_printf("rrb\n");
	rev(stackb);
	ft_node_print_list(*stackb, 'b');
}

//rra and rrb
void	rrr(t_node **stacka, t_node **stackb)
{
	ft_printf("rrr\n");
	rev(stacka);
	rev(stackb);

	ft_node_print_list(*stacka, 'a');
	ft_node_print_list(*stackb, 'b');
}
