# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/10 13:27:06 by jsalmi            #+#    #+#              #
#    Updated: 2020/08/14 15:58:33 by jsalmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libui.a
SRCS = ft_test_libui.c\
	   ft_create_window.c\
	   ft_create_button.c\
	   set_pixel.c
OBJS = $(SRCS:.c=.o)
LIBS = libui.h
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(SRCS) $(FLAGS)
	ar rc $(NAME) $(OBJS) 
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean, all, fclean, re
