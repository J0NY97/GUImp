/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_default_elem_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 10:57:10 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/05 13:31:07 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_element_info		ft_default_elem_info(t_window *win, t_xywh rel_coord)
{
	t_element_info info;

	info.rel_coord = rel_coord;
	info.parent_elem = NULL;
	info.z_buffer = 0;
	info.parent = win->surface;
	info.f = &default_click;
	info.event_handler = &ft_event_handler;
	info.bg_color = 0xf5f5f5;
	info.extra_info = NULL;
	info.info = NULL;
	info.set_text = 0;
	return (info);
}
