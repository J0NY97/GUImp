/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_slider.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 11:18:09 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/02 13:05:08 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_element	*ui_create_slider(t_window *win, t_xywh coord, int min, int max)
{
	t_element_info	info;
	t_element		*elem;

	info.coord = coord;
	info.parent = win->surface;
	info.info = (t_slider *)malloc(sizeof(t_slider));
	info.info_size = 0; // this probably shouldnt be removed, someone who wants to make a custom element can do that using the create_elem()
	info.f = &ft_slider_function; // thsi should be slider specific...
	info.event_handler = &ft_event_handler;
	info.bg_color = 0xffffff;
	info.extra_info = NULL;
	info.set_text = 0;
	// ft_create_text?
	{
		info.text.x = 0;
		info.text.y = 0;
		info.text.text = "slider";
		info.text.color = 0x000000;
		info.text.margin = 0;
		info.text.font = TTF_OpenFont("font.ttf", 32);
	}
	if ((elem = ft_create_element(info)) == NULL)
		ft_putstr("Slider coulndt be created!\n");
	ft_add_element_to_window_elements(win, elem);
	// slider specific info
	{
		((t_slider *)elem->info)->min = min;
		((t_slider *)elem->info)->max = max;
		((t_slider *)elem->info)->value = (max - min) / 2;
		((t_slider *)elem->info)->bar_color = 0xd3d3d3;
	}
	int p = ((float)elem->coord.w / (max - min)) * ((t_slider *)elem->info)->value;
	ft_update_slider_bar(p + elem->coord.x, elem->coord.y, elem);
	return (elem);
}
