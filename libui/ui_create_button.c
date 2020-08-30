/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_create_button.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 11:04:46 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/30 13:24:24 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void		default_click(SDL_Event e, t_element *elem)
{
	ft_putstr("A button was clicked.\n");
}

t_element	*ui_create_button(t_window *win, int x, int y)
{
	t_element_info info;
	t_element	*elem;

	info.x = x;
	info.y = y;
	info.w = 100;
	info.h = 50;
	info.parent = win->surface; // think about this
	info.info = (t_button *)malloc(sizeof(t_button));
	info.info_size = 0; // remove this in another iteration
	info.f = &default_click;
	info.event_handler = &ft_event_handler;
	info.bg_color = 0xffffff;
	info.extra_info = NULL;
	info.set_text = 1;
	// @Improvement: move this to set t_text or something liek that
	{
		info.text.x = 10;
		info.text.y = 5;
		info.text.text = "button";
		info.text.color = 0x000000;
		info.text.margin = 0;
		info.text.font = TTF_OpenFont("font.ttf", 32);
	}
	elem = ft_create_element(info);
	// @Important @Fix: move this to ft_create_element
	ft_add_element_to_window_elements(win, elem);
	return (elem);
}