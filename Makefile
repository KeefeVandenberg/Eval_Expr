#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvandenb <kvandenb@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/16 12:52:47 by kvandenb          #+#    #+#              #
#    Updated: 2017/07/16 21:54:57 by kvandenb         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC	= gcc

FLAGS = -Wall -Wextra -Werror

RM	= rm -f

NAME = eval_expr

HEADER = ft_list.h

SRCS = main.c eval_expr.c do_op.c lib.c

OBJS = main.o eval_expr.o do_op.o lib.o

all: compile

compile :
	$(CC) $(FLAGS) -c $(SRCS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)