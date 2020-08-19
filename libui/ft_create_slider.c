/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_slider.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:20:16 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/19 13:40:15 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int		ft_create_slider(t_slider_info info)
{
	t_slider *slider;

	if (!(slider = (t_slider *)malloc(sizeof(t_slider))))
	{
		ft_putstr("[create_slider] Slider couldnt be malloced.\n");
		return (0);
	}
	slider->x = info.x;
	slider->y = info.y;
	slider->min = info.min;
	slider->max = info.max;
	slider->current = info.current;
//	slider->f = info.f;
	slider->slider_color = info.slider_color;
	slider->bar_color = info.bar_color;
	slider->surface = SDL_CreateRGBSurface(0, info.w, info.h, 32, 0, 0, 0, 0);
	info.win->sliders[++info.win->slider_amount] = slider;
	ft_update_slider(slider, -1, -1);
	return (1);
}
