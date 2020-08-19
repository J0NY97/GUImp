# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/10 13:27:06 by jsalmi            #+#    #+#              #
#    Updated: 2020/08/19 18:23:27 by jsalmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libui.a
SRCS = ft_test_libui.c\
	   ft_create_window.c\
	   ft_create_line.c\
	   ft_create_circle.c\
	   set_pixel.c\
	   hex_to_rgba.c\
	   ft_create_element.c\
	   ft_update_element.c\
	   ft_mouse_button_handler.c\
	   ft_event_poller.c
OBJS = $(SRCS:.c=.o)
LIBS = libui.h
#FLAGS = -Wall -Wextra -Werror

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
