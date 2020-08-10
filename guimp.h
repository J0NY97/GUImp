/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guimp.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 12:48:24 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/10 14:48:57 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUIMP_H
# define GUIMP_H
# include <stdio.h>
# include <math.h>
# include "./libft/libft.h"
# include "./libui/libui.h"
# include "./include/SDL2/SDL.h"
# include "./include/SDL2/SDL_ttf.h"
# include "./include/SDL2/SDL_image.h"

// @Improvement: this should probably get putted in the libui.h
typedef struct	s_win
{
	SDL_Window	*win;
	SDL_Surface	*surface;
	int			x;
	int			y;
	int			w;
	int			h;
	int			resizeable;
}				t_win;

typedef struct	s_info
{
	int			run;

	SDL_Event	event;

	t_win		main;
	t_win		toolbox;
	t_win		layers;

}				t_info;

void			check_input(t_info *info);

#endif
