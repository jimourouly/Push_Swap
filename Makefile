# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 18:23:30 by jroulet           #+#    #+#              #
#    Updated: 2024/07/01 10:37:23 by jroulet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
CC = cc
SRCS =	./push_swap.c \
		./totab.c \
		./ft_node.c \
		./algorythme.c \
		./ft_linkedlist.c \
		./sort/ft_sort.c \
		./sort/push.c \
		./sort/rotate.c \
		./sort/swap.c \
		./sort/reverserotate.c \
		./sort/sort_three.c \
		./sort/sorting.c
OBJS = $(SRCS:.c=.o)

LIBDIR = ./libft
LIBNAME = libft.a

NAME = push_swap

%.o: %.c
	$(CC) $(FLAGS) -g -c $< -o $@

all: $(NAME)

$(NAME): makelibft $(OBJS)
	$(CC) $(OBJS) $(LIBDIR)/$(LIBNAME) -o $(NAME)

makelibft:
	make -C $(LIBDIR)
	cp $(LIBDIR)/$(LIBNAME) .

git: fclean
	git add .
	git commit -m "$t" -m "$b"
	git push

clean:
	make -C $(LIBDIR) clean
	rm -f $(OBJS)
	rm -f ./sort/*.o

fclean: clean
	make -C $(LIBDIR) fclean
	rm -f $(LIBNAME)
	rm -f $(NAME)
	rm -f ./sort/*.o

re: fclean all

.PHONY: debugger compile clean re fclean bonus git all
