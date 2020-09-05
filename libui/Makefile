NAME = libui.a
SRCS = ft_test_libui.c\
	   ft_create_window.c\
	   ft_create_line.c\
	   ft_create_circle.c\
	   set_pixel.c\
	   hex_to_rgba.c\
	   rgb_to_hex.c\
	   ft_create_element.c\
	   ft_update_element.c\
	   ft_event_handler.c\
	   ft_event_poller.c\
	   ft_update_background.c\
	   ft_create_text.c\
	   ft_read_text.c\
	   flood_fill.c\
	   ft_create_square.c\
	   push_pop.c\
	   ft_drop_down.c\
	   popup.c\
	   ui_create_button.c\
	   ui_render.c\
	   ft_add_element_to_window_elements.c\
	   ft_add_window_to_libui_windows.c\
	   ui_libui_init.c\
	   ui_create_surface.c\
	   ui_init_coords.c\
	   ui_create_slider.c\
	   ft_slider_function.c\
	   ft_add_x_to_list.c\
	   ft_add_hotkey.c\
	   file_handling.c\
	   ui_create_drop.c\
	   ft_drop_down_function.c\
	   ft_strjoiner.c\
	   ft_default_elem_info.c\
	   ft_set_icon.c\
	   ft_default_text.c\
	   free.c
OBJS = $(SRCS:.c=.o)
LIBS = libui.h
#FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(SRCS) $(FLAGS)
	ar rc $(NAME) $(OBJS) 
	ranlib $(NAME)
	/bin/rm -f $(OBJS)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean, all, fclean, re
