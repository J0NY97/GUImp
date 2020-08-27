# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/10 12:48:11 by jsalmi            #+#    #+#              #
#    Updated: 2020/08/27 13:42:52 by jsalmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = guimp
SRCS = ./main.c\
		./draw.c\
		./file_handling.c\
		./text_to_screen.c\
		./image_handling.c
OBJS = ./*.o
INCLUDES = ./libft/libft.a\
		   ./libui/libui.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C ./libui/
	gcc -o $(NAME) $(SRCS) $(INCLUDES) -I include -L lib -l SDL2-2.0.0 -l SDL2_ttf-2.0.0 -l SDL2_image-2.0.0

clean:
	/bin/rm -f $(OBJS)
	make -C ./libui/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./libui/ fclean

re: fclean all

.PHONY: clean, all, re, fclean
