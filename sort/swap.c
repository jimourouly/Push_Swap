/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:04:58 by jroulet           #+#    #+#             */
/*   Updated: 2024/06/09 13:20:16 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_node *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

void	sa(t_node **stacka)
{
	ft_printf("sa\n");
	swap(*stacka);
}

void	sb(t_node **stackb)
{
	swap(*stackb);
	ft_printf("sb\n");
}

void	ss(t_node **stacka, t_node **stackb)
{
	swap(*stacka);
	swap(*stackb);
	ft_printf("ss\n");
}
