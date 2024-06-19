# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 18:23:30 by jroulet           #+#    #+#              #
#    Updated: 2024/06/19 12:00:39 by jroulet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
CC = cc
DEBUGGER = -g
SRCS = push_swap.c\
		totab.c\
		ft_linkedlist.c\
		./sort/push.c\
		./sort/rotate.c\
		./sort/swap.c\
		./sort/ft_ll.c\
		./sort/reverserotate.c\
		./sort/tinysort.c\
		./algorythme.c\
		./printorder.c
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

debug: $(NAME)
	$(CC) $(DEBUGGER) $(OBJS) $(LIBDIR)/$(LIBNAME) -o $(NAME)

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
