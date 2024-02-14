/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:24:23 by jroulet           #+#    #+#             */
/*   Updated: 2024/02/14 15:39:01 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct	s_lst
{
	int				value;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_lst;

int		intchecker(char *number);
void	printerror(void);
t_list	*argtreat(int ac, char **av);
void	ft_lst_print(t_list *head);
t_lst	*ft_list_new(int value);

#endif
