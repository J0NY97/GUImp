/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:04:09 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/14 13:24:01 by jsalmi           ###   ########.fr       */
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

typedef struct	s_button_info
{
	int			x;
	int			y;
	int			w;
	int			h;
	char		*text;
	void		(*f)(void);	
}				t_button_info;

// @TODO: different surfaces for different events; (default, hover, press)
typedef struct	s_button
{
	SDL_Surface	*surface;
	void		(*f)(void); // function that will be called on_click
}				t_button;

typedef struct	s_window_info
{
	char		*title;
	int			x;
	int			y;
	int			w;
	int			h;
	int			flags;
	int			resizeable;	
}				t_window_info;

typedef struct	s_window
{
	SDL_Window	*win;
	SDL_Surface	*surface;
	t_button	*buttons;
	//array of elements
	//array of buttons
	//array of pictures
	//font
	//...
}				t_window;

void			ft_test_libui(void);
t_window		*ft_create_window(t_window_info info);
t_button		*ft_create_button(t_button_info info);

#endif
