/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slider_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 11:33:36 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/16 16:52:50 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_update_slider_bar(int click_x, int click_y, t_element *elem)
{
	SDL_Surface *bar;
	SDL_Rect	temp;
	t_slider	*slider;
	float		ppv;
	int			x;
	int			y;

	slider = (t_slider *)elem->info;
	x = click_x - elem->coord.x;
	y = click_y - elem->coord.y;
	bar = SDL_CreateRGBSurface(0, 10, elem->coord.h, 32, 0, 0, 0, 0);
	ft_update_background(elem->states[0], elem->bg_color);
	ft_update_background(elem->states[1], elem->bg_color);
	ft_update_background(elem->states[2], elem->bg_color);
	ft_update_background(bar, slider->bar_color);
	ppv = (slider->max - slider->min) / (float)elem->coord.w;
	temp.x = x - (bar->w / 2);
	temp.y = 0;
	temp.w = bar->w;
	temp.h = bar->h;
	SDL_BlitSurface(bar, NULL, elem->states[0], &temp);
	SDL_BlitSurface(bar, NULL, elem->states[1], &temp);
	SDL_BlitSurface(bar, NULL, elem->states[2], &temp);
	slider->value = (float)ppv * x;
	SDL_FreeSurface(bar);
}

void	ft_slider_function(SDL_Event e, t_element *elem)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
		elem->state = 1;
	if (e.type == SDL_MOUSEMOTION && elem->state == 1)
		elem->state = 2;
	if (e.type == SDL_MOUSEBUTTONUP)
		elem->state = 0;
	if (elem->state == 1 || elem->state == 2)
		ft_update_slider_bar(e.button.x, e.button.y, elem);
}
