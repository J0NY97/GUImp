/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:04:09 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/19 19:39:59 by jsalmi           ###   ########.fr       */
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

typedef struct	s_libui
{
	SDL_Event	event;
}				t_libui;

typedef	struct	s_text_info
{
	int			x;
	int			y;
	int			color;
	char		*text;
	TTF_Font	*font;
}				t_text_info;

struct	s_element_info
{
	int			x;
	int			y;
	int			w;
	int			h;
	int			bg_color;
	void		*parent;
	void		*info;
	void		(*f)(SDL_Event, t_element *);
	int			(*event_handler)(t_libui *, t_element *);
	t_text_info	text_info;
};

struct	s_element
{
	int			x;
	int			y;
	int			w;
	int			h;
	int			bg_color;
	void		*info;
	void		*parent;
	void		(*f)(SDL_Event, t_element *);
	int			(*event_handler)(t_libui *, t_element *);
	t_text_info	text_info;
	SDL_Surface	*surface;
};

////////////////////////////////

struct s_window_info
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
	int			button_amount;
	t_element	*buttons[10];
};

struct s_button_info
{
	int			x;
	int			y;
	int			w;
	int			h;
	int			state;
	int			toggle;
	int			group;
	char		*text;
	void		*info;
	void		(*f)(t_button *);
	TTF_Font	*font;
	t_window	*win;
};

// @TODO: different surfaces for different events; (default, hover, press)
/*
	** state: 0 = default
 			1 = hover
			2 = press
	** group: int the group the button belongs to
	** toggle; -1 not toggleable
				0 not toggled
				1 toggled
*/
struct s_button
{
	int			state;
	int			x;
	int			y;
	char		*text;
	int			toggle;
	int			group;
	TTF_Font	*font;
	SDL_Surface	*surface;
	void		*info;
	void		(*f)(t_button *); // function that will be called on_click
	void		(*event_handler)(t_libui *, t_button *);
};

struct	s_surface_info
{
	int			x;
	int			y;
	int			w;
	int			h;
	int			color;
	t_window	*win;
};

struct	s_surface
{
	int			x;
	int			y;
	SDL_Surface	*surface;
};

struct	s_slider_info
{
	int			x;
	int			y;
	int			w;
	int			h;
	int			min;
	int			max;
	int			current;
	void		(*f)(t_slider *);
	Uint32		slider_color;
	Uint32		bar_color;
	t_window	*win;
};

struct	s_slider
{
	int			x;
	int			y;
	int			min;
	int			max;
	int			current;
	void		(*f)(t_slider *);
	Uint32		slider_color;
	Uint32		bar_color;
	SDL_Surface *surface;
};

typedef struct	s_line
{
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
	double		pytha;

}				t_line;

typedef struct	s_circle
{
	int			r;
	int			y;
	int			x;
	int			xc;
	int			yc;
}				t_circle;

void			ft_test_libui(void);
t_window		*ft_create_window(t_window_info info);
/* BUTTONS */
//int				ft_create_button(t_button_info info);
//int				ft_update_button(t_button *button, int bg_color, int txt_color);
/* SURFACES */
//int				ft_create_surface(t_surface_info info);
//void			ft_update_background(SDL_Surface *surface, Uint32 bg_color);
/* SLIDERS */
//int				ft_create_slider(t_slider_info info);
//void			ft_update_slider(t_slider *slider, int click_x, int click_y);
/* EXTRA */
void			ft_create_line(SDL_Surface *surf, Uint32 color, t_line *l);
void			ft_create_circle(SDL_Surface *surface, Uint32 color, t_circle c);
void			set_pixel(SDL_Surface *surf, int x, int y, Uint32 color);
SDL_Color		hex_to_rgba(int color);

/* TESTS */
t_element		*ft_create_element(t_element_info info);
void			ft_update_element(t_element *elem);
int				ft_mouse_button_handler(t_libui *libui, t_element *elem);
void			ft_event_poller(t_libui *libui);


#endif
