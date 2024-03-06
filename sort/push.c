/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:04:33 by jroulet           #+#    #+#             */
/*   Updated: 2024/03/06 15:04:35 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//push top one from b to a
void    pusha(t_node **stacka, t_node **stackb)
{
    push(stackb, stacka);
    ft_printf("pa\n");
}

//push top one from a to b
void    pushb(t_node **stacka, t_node **stackb)
{
    push(stacka, stackb);
    ft_printf("pb\n");
}

void    push(t_node **src, t_node **dest)
{
    t_node	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}