#include "../push_swap.h"

void	tinysort(t_node *head)
{
	t_node	*current;
	smallestnode(head);
	biggestnode(head);
}

t_node *smallestnode(t_node *head)
{
	t_node *current = head;
	t_node *smallest= head;


	while (current != NULL)
	{
		if (current->value < smallest->value)
		{
			smallest = current;
		}
		current = current->next;
		}
		ft_printf("smallest value %d\n", smallest->value);
	return smallest;

}


t_node *biggestnode(t_node *head)
{
	t_node *current;
	t_node *biggest;

	biggest = head;
	current = head->next;

	while (current != NULL)
	{
		if (current->value > biggest->value)
		{
			biggest = current;
		}
		current = current->next;
	}
	ft_printf("biggest value %d\n", biggest->value);
	return biggest;
}
