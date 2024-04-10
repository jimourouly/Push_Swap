/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:04:33 by jroulet           #+#    #+#             */
/*   Updated: 2024/04/10 16:05:47 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//push top one from b to a
void	pusha(t_node **stacka, t_node **stackb)
{
	push(stackb, stacka);
	ft_printf("\033[0;31m PA - Top 1 B to A \033[0m\n");
}

//push top one from a to b
void	pushb(t_node **stacka, t_node **stackb)
{
	push(stacka, stackb);
	ft_printf("\033[0;31m PB - Top 1 A to B\033[0m\n");
}

void	push(t_node **src, t_node **dest)
{
	t_node	*tmp;

	if (src == NULL || *src == NULL)
		return ;
	tmp = (*src)->next;

	if (dest != NULL)
	{
		(*src)->next = *dest;
		*dest = *src;
	}
	else
	{
		(*src)->next = NULL;
	}
	*src = tmp;
}
