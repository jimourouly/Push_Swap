/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:04:58 by jroulet           #+#    #+#             */
/*   Updated: 2024/05/27 14:59:11 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//do the actual swap
void	swap(t_node *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

// switch top 2 on a
void	sa(t_node **stacka)
{
	ft_printf("sa\n");
	swap(*stacka);
	//ft_node_print_list(*stacka, 'a');
	ft_printf("adresse stacka %p\n", *stacka);
}

// switch top 2 on b
void	sb(t_node **stackb)
{
	swap(*stackb);
	ft_printf("sb\n");
}

// switch top 2 on a and b
void	ss(t_node **stacka, t_node **stackb)
{
	swap(*stacka);
	swap(*stackb);
	ft_printf("ss\n");
	ft_printf("adresse stacka %p\n", *stacka);
	ft_printf("adresse stackb %p\n", *stackb);
}
