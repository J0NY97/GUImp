/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_slider.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:31:38 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/19 12:31:25 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_update_slider(t_slider *slider)
{
	SDL_Surface *bar;
	SDL_Rect	temp;
	float		ppv;
	
	bar = SDL_CreateRGBSurface(0, 20, 10, 32, 0, 0, 0, 0);
	// coloring the slider
	int x = -1;
	int y = -1;
	while (++y < slider->surface->h)
	{
		x = -1;
		while (++x < slider->surface->w)
		{
			set_pixel(slider->surface, x, y, slider->slider_color);
		}
	}
	// making bar the color you want
	y = -1;
	while (++y < bar->h)
	{
		x = -1;
		while (++x < bar->w)
		{
			set_pixel(bar, x, y, slider->bar_color);
		}
	}
	//
	ppv = (float)slider->surface->w / (slider->max - slider->min);
	temp.x = ppv * slider->current - (bar->w / 2);
	temp.y = 0;
	temp.w = bar->w;
	temp.h = bar->h;
	SDL_BlitSurface(bar, NULL, slider->surface, &temp);
}