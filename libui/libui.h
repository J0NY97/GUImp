#ifndef LIBUI_H
# define LIBUI_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <string.h>
# include "../libft/libft.h"
# include "../include/SDL2/SDL.h"
# include "../include/SDL2/SDL_ttf.h"
# include "../include/SDL2/SDL_image.h"
# include <dirent.h>

typedef struct	s_window_info	t_window_info;
typedef struct	s_window		t_window;
typedef struct	s_button_info	t_button_info;
typedef struct	s_button		t_button;
typedef struct	s_surface_info	t_surface_info;
typedef struct	s_surface		t_surface;
typedef struct	s_slider_info	t_slider_info;
typedef struct	s_slider		t_slider;
/////////////
typedef	struct	s_element		t_element;
typedef	struct	s_element_info	t_element_info;
typedef	struct	s_text			t_text;
typedef	struct	s_drop_item		t_drop_item;
typedef	struct	s_drop_down		t_drop_down;
typedef	struct	s_scrollbar		t_scrollbar;
typedef	struct	s_hotkey		t_hotkey;

typedef struct	s_xywh
{
	int			x;
	int			y;
	int			w;
	int			h;
}				t_xywh;

typedef struct	s_libui
{
	SDL_Event	event;
	t_list		*windows;
	t_list		*hotkeys;
	char		*drag_file;
	int			quit;
}				t_libui;

struct			s_hotkey
{
	SDL_Keycode	key;
	void		(*f)(SDL_Event e, t_hotkey *hotkey);
};

struct			s_text
{
	int			x;
	int			y;
	int			color;
	int			margin; // maximum width of the text (parent->w - margin)
	int			centered;
	char		*text;
	int			set_text;
	TTF_Font	*font;
	SDL_Surface *parent;
};

struct	s_element_info
{
	int			x;
	int			y;
	int			w;
	int			h;
	t_xywh		rel_coord;
	int			shadow;
	int			z_buffer;
	int			bg_color;
	size_t		info_size;
	void		*info;
	void		*extra_info;
	void		(*f)(SDL_Event, t_element *);
	int			(*event_handler)(SDL_Event, t_element *);
	int			set_text;
	t_text		text;
	t_element	*parent_elem;
	SDL_Surface	*parent;
};

struct	s_element
{
	int			state; //0 = press, 1 = hover, 2 = click
	int			default_state;
	int			statique;
	int			shadow;
	int			offset_x;
	int			offset_y;
	t_xywh		coord;
	t_xywh		rel_coord;
	int			bg_color;
	void		*info;
	void		*extra_info;
	void		(*f)(SDL_Event, t_element *);
	int			(*event_handler)(SDL_Event, t_element *);
	int			loop;
	t_text		text;
	t_element	*parent_elem;
	SDL_Surface	*parent;
	SDL_Surface *surface;
	SDL_Surface	*states[3];
};

struct			s_button
{
	int			type;
	void		*extra;
	size_t		size;
};

struct			s_slider
{
	int			min;
	int			max;
	int			value;
	int			bar_color;
};

struct			s_drop_item
{
	int			item_nbr;
	int			selected;
};

struct			s_drop_down
{
	int			item_amount;
	t_element	*items[5]; // find on a better put
	int			drop_height;
	int			height;
	size_t		size;
};

struct			s_surface
{
	void		*extra;
};

struct			s_scrollbar
{
	t_element	*target;
};

struct			s_window_info
{
	char		*title;
	t_xywh		coord;
	int			x;
	int			y;
	int			w;
	int			h;
	int			flags;
	int			resizeable;
	int			bg_color;	
};

struct s_window
{
	SDL_Window	*win;
	SDL_Surface	*surface;
	t_list		*elements;
	t_list		*non_render;
	Uint32		id;
	int			bg_color;
};

typedef struct	s_shapes
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			fill;
	int			size;
	int			color;
}				t_shapes;

typedef	struct	s_coords
{
	int			x;
	int			y;
}				t_coords;

void			ft_test_libui(void);
/*
 ** EXTRA
*/
void			push_list(t_list **lst, void *content, size_t content_size);
void			*pop_list(t_list **lst);
char			*drag_and_drop(SDL_Event e);
SDL_Surface		*load_image(char *file);
int				save_image(SDL_Surface *img, char *file);
void			ft_read_text(t_element *elem, int size);
char			*ft_strjoiner(char *first, ...);
void			notify(char *title, char *msg);
void			error_msg(char *str);
void			text_area(SDL_Event e, t_element *elem);
void			ft_add_element_to_window_elements(t_window *win, t_element *elem);
void			ft_add_to_non_render_elem_list(t_window *win, t_element *elem);
void			ft_add_window_to_libui_windows(t_libui *libui, t_window *win);
void			ui_libui_init(t_libui *libui);
void			ft_add_hotkey(t_libui *libui, SDL_Keycode, void (*f)());
void			ft_set_icon(SDL_Window *window, char *dir);
SDL_Surface		*ft_scale_surface(SDL_Surface *surface, int w, int h);
SDL_Surface		*ft_scale_surface_aspect(SDL_Surface *surface, int w, int h);
SDL_Surface		*ft_create_rgba_surface(int w, int h);
SDL_Rect		ft_sdl_rect(int x, int y, int w, int h);
/*
 ** Popup
*/
t_list			*dir_open(char *folder_path, unsigned char type, int *size);
char			*dir_explore(char *folder_path, unsigned char type);
char			*input_popup(int x, int y);
void			popup_coord(int *x, int *y, int w, int h);
int				true_false_popup(int x, int y, char *msg);
void			popup_sdl_init(t_libui *libui);
void			char_del(void *name, size_t size);
void			popup_char_func(SDL_Event e, t_element *elem);
void			popup_int_func(SDL_Event e, t_element *elem);
/*
 ** Draw
*/
void			flood_fill(SDL_Surface *surface, Uint32 w_color, Uint32 r_color, int x, int y);
void			set_pixel(SDL_Surface *surf, int x, int y, Uint32 color);
void			set_blended_pixel(SDL_Surface *surf, int x, int y, Uint32 color);
SDL_Color		hex_to_rgba(int color);
int				rgb_to_hex(int r, int g, int b, int a);
Uint32			get_color(SDL_Surface *surface, int x, int y);
void			ft_create_square(SDL_Surface *surface, Uint32 color, t_shapes l);
void			ft_create_line(SDL_Surface *surf, Uint32 color, t_shapes l);
void			ft_create_circle(SDL_Surface *surface, Uint32 color, t_shapes c);
Uint32			get_color(SDL_Surface *surface, int x, int y);
/*
 ** Math
*/
int				ft_clamp(int val, int min, int max);
int				ft_min(int a, int b);
int				ft_max(int a, int b);
/*
 ** UI
*/
t_window		*ft_create_window(t_libui *libui, t_window_info info);
t_element_info	ft_default_elem_info(t_window *win, t_xywh coord, t_element *parent);
t_element		*ft_create_element(t_element_info info);
t_element		*ui_create_button(t_window *win, t_xywh coord, t_element *parent);
t_element		*ui_create_surface(t_window *win, t_xywh coord, t_element *parent);
t_element		*ui_create_slider(t_window *win, t_xywh coord, t_element *parent, int min, int max);
t_element		*ui_create_drop(t_window *win, t_xywh coord, t_element *elem);
t_element		*ui_create_scrollbar(t_window *win, t_element *elem);
t_xywh			ui_init_coords(int x, int y, int w, int h);
void			ft_default_text(t_text *text, char *txt);
/*
 ** UI HELP
*/
void			ft_update_background(SDL_Surface *surface, Uint32 color);
void			ft_create_text(t_text *text);
void			ft_drop_down_add_item(t_window *win, t_element *drop, char *name);
void			ft_slider_function(SDL_Event e, t_element *elem);
void			ft_update_slider_bar(int click_x, int click_y, t_element *elem);
void			ft_update_drop(t_element *elem);
void			ft_drop_down_function(SDL_Event e, t_element *elem);
void			ft_set_slider_value(t_element *elem, int new_value);
void			ft_set_element_image(t_element *elem, SDL_Surface *img);
void			ft_set_font(t_text *text, char *font, int size);
void			ft_set_text(t_text *text, char *txt);
void			ft_update_elem_background(t_element *elem, Uint32 color);
/*
 ** Render
*/
void			ft_update_element(t_element *elem);
void			ui_render(t_window *win);
void			ui_render_element(SDL_Surface *win, t_element *elem);
/*
** Free
*/
void			free_element(t_element *elem);
void			free_window(t_window *win);
void			free_libui(t_libui *libui);
/*
 ** Prefabs
*/
t_element		*prefab_tools_init(t_window *win, int x, int y);
/*
 ** Event handling
*/
int				ft_event_handler(SDL_Event e, t_element *elem);
void			ft_event_poller(t_libui *libui);
void			ft_drop_item_function(SDL_Event e, t_element *elem);
void			ft_button_handler(SDL_Event e, t_element *elem);
void			default_click(SDL_Event e, t_element *elem);
int				ft_keyboard_handler(t_libui *libui);
#endif
