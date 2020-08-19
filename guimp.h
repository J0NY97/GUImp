/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guimp.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 12:48:24 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/19 14:02:25 by nneronin         ###   ########.fr       */
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
	int			type;
	int			size;
	int			color;
	int			old_x;
	int			old_y;
}				t_brush;

struct	s_info
{
	int			run;
	TTF_Font	*font;

	SDL_Event	event;

	t_window	*main;
	t_window	*toolbox;
	t_window	*layers;

	t_brush		brush;
	int			draw;
};

void			event_handler(t_info *info);
void			check_input(t_info *info);

#endif
