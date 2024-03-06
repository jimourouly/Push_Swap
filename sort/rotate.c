/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:04:47 by jroulet           #+#    #+#             */
/*   Updated: 2024/03/06 15:04:49 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    rotate(t_node **stack)
{
    t_node *tmp;
    t_node *bottom;

    tmp = *stack;
    *stack = (*stack)->next;
    bottom = getbottomnode(*stack);
    tmp->next = NULL;
    bottom->next = tmp;
}

//ascending all node in stack a
void    ra(t_node *stacka)
{
    rotate(&stacka);
    ft_printf("ra\n");
}

//ascending all node in stack b
void    rb(t_node *stackb)
{
    rotate(&stackb);
    ft_printf("rb\n");
}

//ascending all node in both stack
void    rr(t_node *stacka, t_node *stackb)
{
    ra(stacka);
    rb(stackb);
    ft_printf("rr\n");
}

