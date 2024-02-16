/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkedlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:20:01 by jroulet           #+#    #+#             */
/*   Updated: 2024/02/16 18:07:54 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printlist(t_list *head)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = head;
	while (temp != NULL)
	{
		ft_printf("value = :%d:\n", temp->content);
		temp = temp->next;
		i++;
	}
}

void	ft_findlst(t_lilst *head, int value)
{
	t_list	*temp;

	temp = head;
	while (temp != NULL)
	{
		if (temp->value == value)
			printerror();
		temp = temp->next;
	}
}

void	lstcreator(int ac, char **av)
{
	char	**tab;
	int		i;
	t_list	*new;
	t_list	*head;

	head = NULL;
	i = 0;
	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		while (tab[i] != NULL)
		{
			new = ft_lstnew(ft_atoi(tab[i]));
			ft_lstadd_back(&head, new);
			i++;
		}
		ft_printlist(head);
	}
	else
	{
		i = 1;
		while (i < ac)
		{
			new = ft_lstnew(ft_atoi(av[i]));
			ft_lstadd_back(&head, new);
			i++;
		}
		ft_printlist(head);
	}
}
