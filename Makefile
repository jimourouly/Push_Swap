# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 18:23:30 by jroulet           #+#    #+#              #
#    Updated: 2024/02/10 18:33:29 by jroulet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
CC = cc
SRCS = push_swap.c
OBJS = $(SRCS:c=.o)

LIBDIR = ./libft
LIBNAME = libft.a

NAME = push_wap.a

makelibft:
	make -C $(LIBDIR)
	cp $(LIBDIR)/$(LIBNAME) .
	mv $(LIBNAME) $(NAME)

git: fclean
	git add .
	git commit -m "$t" -m "$b"
	git push

clean:
	make -C $(LIBDIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBDIR) fclean
	rm -f $(NAME)

.PHONY: clean re fclean bonus git all
