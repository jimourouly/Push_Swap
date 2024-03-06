/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:04:40 by jroulet           #+#    #+#             */
/*   Updated: 2024/03/06 15:04:42 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    rev(t_node **stack)
{
    t_node  *tmp;
    t_node  *bottom;
    t_node  *prev;
    t_node  *current;

    prev = NULL;
    current = *stack;
    while (current->next != NULL)
    {
        prev = current;
        current = current->next;
    }
    bottom = current;
    prev->next = NULL;
    *stack = bottom;
    (*stack)->next = tmp;
}

//descend all node from a
void    rra(t_node **stacka)
{
    rev(stacka);
    ft_printf("rra\n");
}

//descend all node from b
void    rrb(t_node **stackb)
{
    rev(stackb);
    ft_printf("rrb\n");
}

//rra and rrb
void    rrr(t_node **stacka, t_node **stackb)
{
    rra(stacka);
    rrb(stackb);
    ft_printf("rrr\n");
}
