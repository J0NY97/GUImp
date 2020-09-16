NAME = guimp
SRCS = ./main.c\
		./draw.c\
		./text_to_screen.c\
		./zoom_and_move.c\
		./shapes.c\
		./shape_button_init.c\
		./load_icons.c
OBJS = ./*.o
INCLUDES = ./libft/libft.a\
		   ./libui/libui.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C ./libui/
	@gcc -o $(NAME) $(SRCS) $(INCLUDES) -I include -L lib -l SDL2-2.0.0 -l SDL2_ttf-2.0.0 -l SDL2_image-2.0.0
	@echo "$(NAME) was successfully created."

clean:
	@/bin/rm -f $(OBJS)
	@echo "guimp was cleaned."

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C ./libui/ fclean

re: fclean all

.PHONY: clean, all, re, fclean
