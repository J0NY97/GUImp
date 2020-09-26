NAME = guimp
DIR_S = ./srcs
INC	=	.	
SRC	=	main.c \
		draw.c \
		text_to_screen.c \
		zoom_and_move.c \
		shapes.c \
		shape_button_init.c \
		guimp_quit.c \
		load_icons.c \
		init_elem_group.c \
		init_drop_down.c \
		init_hotkeys.c \
		init_slider.c \
		init_tool_buttons.c \
		init_layers.c \
		init_windows.c \
		init_utility_elems.c \
		init_brush.c \
		ft_toggle_elem_group.c \
		save_img.c \
		add_new_layer.c \
		reset_workspace.c \
		open_button.c \

SRCS = $(addprefix $(DIR_S)/,$(SRC))
OBJS = ./*.o
INCLUDES = -I libft -L libft -I libui -L libui -I ft_printf -L ft_printf -I$(INC)
LIBS = libft/libft.a libui/libui.a ft_printf/libprintf.a
FLAGS = -Wall -Wextra -Werror
SDL = -I ./libui/SDL2/includes -L ./libui/SDL2/lib -l SDL2-2.0.0 -l SDL2_ttf-2.0.0 -l SDL2_image-2.0.0


all: $(NAME)

$(NAME):
	@gcc -o $(NAME) $(SRCS) $(INCLUDES) $(LIBS) $(SDL)
	@echo "$(NAME) was successfully created."

clean:
	@/bin/rm -f $(OBJS)
	@echo "guimp was cleaned."

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean, all, re, fclean
