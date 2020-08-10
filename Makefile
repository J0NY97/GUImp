# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/10 12:48:11 by jsalmi            #+#    #+#              #
#    Updated: 2020/08/10 14:32:53 by jsalmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = guimp
SRCS = ./main.c\
	   ./input.c
OBJS = ./*.o
INCLUDES = ./libft/libft.a\
		   ./libui/libui.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRCS) $(INCLUDES) -L lib -l SDL2-2.0.0 -l SDL2_ttf-2.0.0

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean, all, re, fclean
