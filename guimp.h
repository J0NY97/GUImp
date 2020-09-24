#ifndef GUIMP_H
# define GUIMP_H
# include <stdio.h>
# include <math.h>
# include "./libft/libft.h"
# include "./libui/libui.h"
# include "./libft/ft_printf/ft_printf.h"
# include "./include/SDL2/SDL.h"
# include "./include/SDL2/SDL_ttf.h"
# include "./include/SDL2/SDL_image.h"

#define POS(n) ((n) < 0 ? 0 - (n) : (n))

typedef struct	s_info	t_info;

typedef struct	s_brush
{
	float		aspect_x;
	float		aspect_y;
	int			zoom;
	int			shape_type;
	t_shapes 	shape;
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

struct			s_info
{
	int			run;
	int			draw;

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
	t_element	*drawing_surface[5]; // the real surfaces
	
	t_element	*screen_surface; // the surface that will be shown on the screen
	t_element	*hidden_surface; // the surface that will have the brush types drawn on it

	t_element	*layer_menu;
	t_element	*layer_layers[5];
	t_element	*layer_buttons[5];

	t_brush		brush;
};

void			event_handler(t_info *info);
void			draw(SDL_Event event, t_element *elem);
void			text_to_screen(SDL_Surface *surface, t_shapes l, char *str, char *font_dir);
int				load_font(char *file, TTF_Font *font);
void			zoom_and_move(t_element *elem, SDL_Event event, int org_w, int org_h);
void			trace_shape(t_info *info);
void			select_shape(SDL_Surface *surf, t_brush *brush);
void			shape_buttons_init(t_info *info);
void			draw_buttons(SDL_Event e, t_element *elem);
void			shape_load(t_info *info);
void			tooltips_load(t_info *info);
void			sticker_load(t_info *info);
void			guimp_quit(t_info *info);

#endif
