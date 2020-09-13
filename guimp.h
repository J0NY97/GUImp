#ifndef GUIMP_H
# define GUIMP_H
# include <stdio.h>
# include <math.h>
# include "./libft/libft.h"
# include "./libui/libui.h"
# include "./include/SDL2/SDL.h"
# include "./include/SDL2/SDL_ttf.h"
# include "./include/SDL2/SDL_image.h"

typedef struct	s_info	t_info;
/*
	**	type; 	0 = deletion
				1 = circle
				2 = square
				3 = ...
	**	size;	radius of the brush
*/

typedef	struct	s_more_info
{
	void		*data1;
	void		*data2;
	void		*data3;
	void		*data4;
	void		*data5;
	void		*data6;
}				t_more_info;

typedef struct	s_brush
{
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
	t_list		*elements;
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

struct			s_info
{
	int			run;
	int			draw;
	TTF_Font	*font;

	SDL_Event	event;
	
	t_win		*toolbox;
	t_win		*main;
	t_win		*layers;

	t_tooltips	tooltips;

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
void			check_input(t_info *info);
void			draw(SDL_Event event, t_element *elem);
void			text_to_screen(SDL_Surface *surface, t_shapes l, t_brush *brush);
int				load_font(char *file, TTF_Font *font);
void			zoom_and_move(t_element *elem, SDL_Event event, int org_w, int org_h);

/*
** Boonus
*/
char				*ft_strjoiner(char *first, ...);
#endif
