# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 18:23:30 by jroulet           #+#    #+#              #
#    Updated: 2024/02/23 14:25:45 by jroulet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
CC = cc
DEBUGGER = -g 
SRCS = push_swap.c\
	   totab.c\
	   tester.c\
	   ft_linkedlist.c
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
