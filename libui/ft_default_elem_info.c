/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_default_elem_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 10:57:10 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/26 13:38:43 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_element_info	ft_default_elem_info(t_window *win,
		t_xywh rel_coord, t_element *parent)
{
	t_element_info info;

	info.rel_coord = rel_coord;
	info.parent_elem = parent;
	if (win)
		info.parent = win->surface;
	info.f = &default_click;
	info.event_handler = &ft_event_handler;
	info.bg_color = 0xfff5f5f5;
	info.extra_info = NULL;
	info.info = NULL;
	info.set_text = 0;
	info.shadow = 1;
	return (info);
}
