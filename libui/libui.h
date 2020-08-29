/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:04:09 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/29 14:15:00 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef	struct	s_emp
{
	int			x;
	int			y;
	int			i;
	int			j;
	int			a;
	int			b;
	int			k;
}				t_emp;

typedef struct	s_libui
{
	SDL_Event	event;
}				t_libui;

struct			s_text
{
	int			x;
	int			y;
	int			color;
	char		*text;
	TTF_Font	*font;
	SDL_Surface *surface;
	SDL_Surface *parent;
};

struct	s_element_info
{
	int			x;
	int			y;
	int			w;
	int			h;
	int			bg_color;
	size_t		info_size;
	void		*info;
	void		*extra_info;
	void		(*f)(SDL_Event, t_element *);
	int			(*event_handler)(t_libui *, t_element *);
	int			set_text;
	t_text		text;
	SDL_Surface	*parent;
};

struct	s_element
{
	int			x;
	int			y;
	int			w;
	int			h;
	int			bg_color;
	void		*info;
	void		*extra_info;
	void		(*f)(SDL_Event, t_element *);
	int			(*event_handler)(t_libui *, t_element *);
	int			set_text;
	t_text		text;
	SDL_Surface	*parent;
	SDL_Surface	*surface;
};

struct			s_button
{
	int			state;
	int			type;
	void		*extra;
	size_t		size;
};

struct			s_slider
{
	int			min;
	int			max;
	int			value;
	int			clicked;
	int			bar_color;
	size_t		size;
};

struct			s_window_info
{
	char		*title;
	int			x;
	int			y;
	int			w;
	int			h;
	int			flags;
	int			resizeable;	
};

struct s_window
{
	SDL_Window	*win;
	SDL_Surface	*surface;
	Uint32		id;
};

typedef struct	s_shapes
{
	int			size;
	int			x;
	int			y;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			cath_x;
	int 		cath_y;
	int			overflow_x;
	int			overflow_y;
}				t_shapes;

typedef	struct	s_coords
{
	int			x;
	int			y;
}				t_coords;

void			ft_test_libui(void);
t_window		*ft_create_window(t_window_info info);
/* EXTRA */
void			ft_create_line(SDL_Surface *surf, Uint32 color, t_shapes l);
void			ft_create_circle(SDL_Surface *surface, Uint32 color, t_shapes c, int i);
void			set_pixel(SDL_Surface *surf, int x, int y, Uint32 color);
SDL_Color		hex_to_rgba(int color);
int				rgb_to_hex(int r, int g, int b);
Uint32			get_color(SDL_Surface *surface, int x, int y);
void			flood_fill(SDL_Surface *surface, Uint32 w_color, Uint32 r_color, int x, int y);
void			ft_create_square(SDL_Surface *surface, Uint32 color, t_shapes l);
void			push_list(t_list **lst, void *content, size_t content_size);
void			*pop_list(t_list **lst);

/* TESTS */
t_element		*ft_create_element(t_element_info info);
void			ft_update_element(t_element *elem);
int				ft_mouse_button_handler(t_libui *libui, t_element *elem);
void			ft_event_poller(t_libui *libui);
void			ft_update_background(SDL_Surface *surface, Uint32 color);
void			ft_create_text(t_text *text);
char			*ft_read_text(int size);
void			notify(char *title, char *msg);
void			error_msg(char *str);

#endif
