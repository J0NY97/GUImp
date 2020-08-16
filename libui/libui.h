/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:04:09 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/16 16:21:46 by jsalmi           ###   ########.fr       */
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
	t_button	*buttons[10]; // remove this mallco
	int			surface_amount;
	t_surface	*surfaces[10];
	//array of elements
	//array of buttons
	//array of pictures
	//font
	//.
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

void			ft_test_libui(void);
t_window		*ft_create_window(t_window_info info);
int				ft_create_button(t_button_info info);
int				ft_update_button(t_button *button, int bg_color, int txt_color);
int				ft_create_surface(t_surface_info info);
void			set_pixel(SDL_Surface *surf, int x, int y, Uint32 color);
SDL_Color		hex_to_rgba(int color);

#endif
