# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 18:23:30 by jroulet           #+#    #+#              #
#    Updated: 2024/02/17 18:40:08 by jroulet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
CC = cc
DEBUGGER = -g 
SRCS = push_swap.c\
	   ft_linkedlist.c\
	   totab.c
OBJS = $(SRCS:.c=.o)

LIBDIR = ./libft
LIBNAME = libft.a

NAME = push_swap.a

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
	$(CC) $(DEBUGGER) $(NAME) $(LIBDIR)/$(LIBNAME)

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
