/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_default_elem_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 10:57:10 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/05 11:09:36 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_element_info		ft_default_elem_info(t_window *win, t_xywh coord)
{
	t_element_info info;

	info.coord = coord;
	info.parent = win->surface;
	info.f = &default_click;
	info.event_handler = &ft_event_handler;
	info.bg_color = 0xf5f5f5;
	info.extra_info = NULL;
	info.info = NULL;
	info.set_text = 0;
	return (info);
}
