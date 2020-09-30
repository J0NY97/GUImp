/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guimp.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:01:05 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/30 16:06:48 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUIMP_H
# define GUIMP_H
# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "./libui/libui.h"
# include "./ft_printf/ft_printf.h"
# include "SDL2/includes/SDL.h"
# include "SDL2/includes/SDL_ttf.h"
# include "SDL2/includes/SDL_image.h"

# define POS(n)			((n) < 0 ? 0 - (n) : (n))
# define LAYER_NBR		5
# define HIDDEN_SURF	info->hidden_surface->surface


typedef struct	s_brush
{
	float		aspect_x;
	float		aspect_y;
	int			zoom;
	int			shape_type;
	t_shapes	shape;
	int			draw;
	int			type;
	int			size;
	int			color;
	char		*font_dir;
	TTF_Font	*font;
	char		*str;
	SDL_Surface	*stickers[5];
	int			selected_sticker;
	int			selected_layer;
}				t_brush;

typedef	struct	s_win
{
	t_window	*window;
	int			elem_amount;
}				t_win;

typedef	struct	s_tooltips
{
	SDL_Surface	*pipette;
	SDL_Surface	*move;
	SDL_Surface	*flood;
	SDL_Surface	*sticker;
	SDL_Surface *shapes;
	SDL_Surface *circle;
	SDL_Surface *deletion;
}				t_tooltips;

typedef struct	s_shape_img
{
	SDL_Surface *orb;
	SDL_Surface *square;
	SDL_Surface *tube;
}				t_shape_img;

typedef struct	s_info
{
	int			run;
	int			draw;
	t_brush		brush;
	t_win		*toolbox;
	t_win		*main;
	t_win		*layers;
	t_tooltips	tooltips;
	t_shape_img	shape_img;
	t_element	*r_slider;
	t_element	*g_slider;
	t_element	*b_slider;
	t_element	*a_slider;
	t_element	*size_slider;
	t_element	*brush_color;
	int			brush_button_amount;
	t_element	*buttons[8];
	int			shapes_nbr;
	t_element	*shapes[3];
	t_element	*text_area;
	t_element	*save_button;
	t_element	*new_layer_button;
	t_element	*clear_workspace;
	t_element	*font_button;
	t_element	*drop_down;
	t_element	*font_down;
	t_element	*brush_menu;
	t_element	*col_menu;
	t_element	*shape_menu;
	int			layer_amount;
	t_element	*drawing_surface[5];
	t_element	*screen_surface;
	t_element	*hidden_surface;
	t_element	*layer_menu;
	t_element	*layer_layers[5];
	t_element	*layer_buttons[5];
}				t_info;

int				load_font(char *file, TTF_Font *font);
void			event_handler(t_info *info);
void			draw(SDL_Event event, t_element *elem);
void			text_to_screen(SDL_Surface *surface,
					t_shapes l, char *str, char *font_dir);
void			zoom_and_move(t_element *elem,
					SDL_Event event, int org_w, int org_h);
void			trace_shape(t_info *info);
void			select_shape(SDL_Surface *surf, t_brush *brush);
void			shape_buttons_init(t_info *info);
void			shape_load(t_info *info);
void			tooltips_load(t_info *info);
void			sticker_load(t_info *info);
void			guimp_quit(t_info *info);
void			menu_init(t_info *info);
void			drop_down_init(t_info *info);
void			hotkey_init(t_info *info, t_libui *libui);
void			slider_init(t_info *info);
void			tool_buttons_init(t_info *info);
void			layer_init(t_info *info);
void			window_init(t_libui *libui, t_info *info);
void			ft_toggle_elem_group(SDL_Event e, t_element *elem);
void			utility_init(t_info *info);
void			save_img(SDL_Event e, t_element *elem);
void			add_new_layer(SDL_Event e, t_element *elem);
void			reset_workspace(SDL_Event e, t_element *elem);
void			open_button(SDL_Event e, t_element *elem);
void			init_brush(t_info *info);
void			update_hidden_surface(t_info *info, t_libui *libui);
void			update_brush(t_info *info);
void			update_layers(t_info *info);
void			drag_drop(t_info *info, t_libui *libui);

#endif
