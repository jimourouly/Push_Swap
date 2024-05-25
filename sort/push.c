/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:04:33 by jroulet           #+#    #+#             */
/*   Updated: 2024/05/25 11:44:08 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//push top one from b to a
void	pusha(t_node **stacka, t_node **stackb)
{

	//ft_printf("\033[0;31m PA - Top 1 B to A \033[0m\n");
	ft_printf("pa\n");
	push(stackb, stacka);
	//ft_node_print_list(*stacka, 'a');
	//ft_node_print_list(*stackb, 'b');
}

//push top one from a to b
void	pushb(t_node **stacka, t_node **stackb)
{

	//ft_printf("\033[0;31m PB - Top 1 A to B\033[0m\n");
	ft_printf("pb\n");
	push(stacka, stackb);
	//ft_node_print_list(*stacka, 'a');
	//ft_node_print_list(*stackb, 'b');
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
