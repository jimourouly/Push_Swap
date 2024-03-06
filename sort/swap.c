/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:04:58 by jroulet           #+#    #+#             */
/*   Updated: 2024/03/06 18:11:50 by jroulet          ###   ########.fr       */
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
	swap(*stacka);
	ft_printf("\033[0;31m SA - swap the 2 top on A\033[0m\n");
}

// switch top 2 on b
void	sb(t_node **stackb)
{
	swap(*stackb);
	ft_printf("\033[0;31m SB -swap the 2 top on B\033[0m\n");
}

// switch top 2 on a and b
void	ss(t_node **stacka, t_node **stackb)
{
	swap(*stacka);
	swap(*stackb);
	ft_printf("\033[0;31m SS - swap the 2 top on A and B\033[0m\n");
}
