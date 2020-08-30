/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_create_surface.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 16:06:38 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/30 18:49:35 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_element	*ui_create_surface(t_window *win, t_xywh coord)
{
	t_element_info	info;
	t_element		*elem;

	info.coord = coord;
	info.parent = win->surface;
	info.info = (t_surface *)malloc(sizeof(t_surface));
	info.info_size = 0; // remove in later iteration
	info.f = &default_click;
	info.event_handler = &ft_event_handler;
	info.bg_color = 0xffffff;
	info.extra_info = NULL;
	info.set_text = 0;
	elem = ft_create_element(info);
	ft_add_element_to_window_elements(win, elem);
	return (elem);
}
