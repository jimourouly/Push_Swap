/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:24:23 by jroulet           #+#    #+#             */
/*   Updated: 2024/02/17 16:57:03 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

int		intchecker(char *number);
void	printerror(void);
void	argtreat(int ac, char **av);
void	ft_lst_print(t_list *head);
void	lstcreator(int ac, char **av);
void	ft_printlst(t_list *head);

#endif
