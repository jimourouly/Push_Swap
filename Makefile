# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 18:23:30 by jroulet           #+#    #+#              #
#    Updated: 2024/03/25 15:38:11 by jroulet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
CC = cc
DEBUGGER = -g
SRCS = push_swap.c\
	   totab.c\
	   tester.c\
	   ft_linkedlist.c\
	   ./sort/push.c\
	   ./sort/rotate.c\
	   ./sort/swap.c\
	   ./sort/reverserotate.c\
	   ./sort/tinysort.c\
	   ./sort/algorythme.c
OBJS = $(SRCS:.c=.o)

LIBDIR = ./libft
LIBNAME = libft.a

NAME = push_swap.a

%.o: %.c
	$(CC) $(CFLAGS) -g -c $< -o $@

all: $(NAME)


$(NAME): makelibft $(OBJS)
	ar -r $(NAME) $(OBJS)

makelibft:
	make -C $(LIBDIR)
	cp $(LIBDIR)/$(LIBNAME) .
	mv $(LIBNAME) $(NAME)

compile: all
	$(CC) $(NAME) $(LIBDIR)/$(LIBNAME)

debug: all
	$(CC) -fsanitize=address $(DEBUGGER) $(NAME) $(LIBDIR)/$(LIBNAME)

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
	rm ./a.out

re: fclean all

.PHONY: debugger compile clean re fclean bonus git all
