#include "../push_swap.h"
void	ft_node_print_list(t_node *head, char stack)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = head;
	if (stack == 'a')
	{
		while (temp != NULL)
		{
			//ft_printf("\033[0;34mstack%c [%d] value :%d: index :%d: indexbin :%d:\033[0m\n",stack, i, temp->value, temp->index, ft_inttobin(temp->index));
			ft_printf("\033[0;34mstack%c value :%d: index :%d: indexbin :%d: address %p \033[0m\n",stack,  temp->value, temp->index, temp->index, temp->value);
			temp = temp->next;
			i++;
		}
	}
	else
	{
		while (temp != NULL)
		{
			//ft_printf("\033[0;32mstack%c [%d] value :%d: index :%d: indexbin :%d: \033[0m\n",stack, i, temp->value, temp->index, ft_inttobin(temp->index));
			ft_printf("\033[0;32mstack%c value :%d: index :%d: indexbin :%d: \033[0m\n",stack, temp->value, temp->index, temp->index);
			temp = temp->next;
			i++;
		}
	}
	ft_printf("\n");
	//ft_printf("\n");
}
