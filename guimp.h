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
typedef struct	s_brush
{
	int			draw;
	int			type;
	int			size;
	int			color;
	int			old_x;
	int			old_y;
	char		*font_dir;
	TTF_Font	*font;
	t_text		*text_area;
}				t_brush;

typedef	struct	s_win
{
	t_window	*window;
	int			elem_amount;
	t_list		*elements;
}				t_win;

struct			s_info
{
	int			run;
	TTF_Font	*font;

	SDL_Event	event;
	
	t_win		*toolbox;
	t_win		*main;
	t_win		*layers;

	t_element	*r_slider;
	t_element	*g_slider;
	t_element	*b_slider;
	t_element	*size_slider;
	t_element	*brush_color;
	
	int			brush_button_amount;	
	t_element	*buttons[8];

	t_element	*drawing_surface[1];
	t_element	*text_area;
	t_element	*save_button;
	t_element	*new_layer_button;
	t_element	*font_button;
	t_element	*drop_down;

	t_brush		brush;
	int			draw;
};

void			event_handler(t_info *info);
void			check_input(t_info *info);
void			draw(SDL_Event event, t_element *elem);
void			text_to_screen(SDL_Surface *surface, t_shapes l, t_brush *brush);
int				load_font(char *file, TTF_Font *font);

/*
** Boonus
*/
char				*ft_strjoiner(char *first, ...);
#endif
