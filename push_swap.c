/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:23:59 by jroulet           #+#    #+#             */
/*   Updated: 2024/06/12 18:41:06 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <limits.h>

void	printerror(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}
// free the char tab

void	freetab(char **tab, int ac)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
	}
	else
	{
		while (i < ac -1)
		{
			free(tab[i]);
			i++;
		}
	}
	free(tab);
}

// return the linkedlist with value from inttab
t_node	*create_linked_list(int *inttab, int len)
{
	int		i;
	t_node	*head;
	t_node	*temp;

	head = NULL;
	i = 0;
	while (i < len)
	{
		temp = ft_node_create_new(inttab[i]);
		temp->next = NULL;
		ft_node_insert_to_end(&head, temp);
		i++;
	}
	return (head);
}

void free_linked_list(t_node *head) {
    t_node *tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int	main(int ac, char **av)
{
	int		*inttab;
	t_node	*head;
	t_node	*stackb;
	int		len;

	stackb = NULL;
	if (ac == 1)
		return (0);
	inttab = tabint(ac, av, &len);
	if (!inttab)
		printerror();
	head = create_linked_list(inttab, len);
	if (!sortedlist(head))
	{
		simplifier(head);
		len = ft_node_length(head);
		if (len == 2)
			sa(&head);
		else if (len == 3)
			tinysort(&head);
		else if (len <= 5)
			sortfive(&head);
		else
			bigsort(head, stackb);
	}
	free_linked_list(head);
	free_linked_list(stackb);
	free(inttab);
}
