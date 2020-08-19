/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_slider.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:31:38 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/19 14:32:58 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_update_slider(t_slider *slider, int click_x, int click_y)
{
	SDL_Surface *bar;
	SDL_Rect	temp;
	float		ppv;
	
	bar = SDL_CreateRGBSurface(0, 20, slider->surface->h, 32, 0, 0, 0, 0);
	
	ft_update_background(slider->surface, slider->slider_color);
	ft_update_background(bar, slider->bar_color);

	ppv = (float)slider->surface->w / (slider->max - slider->min);
	if (click_x == -1  && click_y == -1)
		temp.x = ppv * slider->current - (bar->w / 2);	
	else
	{
		temp.x = click_x - (bar->w / 2);
		slider->current = ppv * click_x;
	}
	temp.y = 0;
	temp.w = bar->w;
	temp.h = bar->h;
	SDL_BlitSurface(bar, NULL, slider->surface, &temp);
}
