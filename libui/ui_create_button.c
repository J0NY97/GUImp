/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_create_button.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 11:04:46 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/05 11:09:58 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void		default_click(SDL_Event e, t_element *elem)
{
	ft_putstr("A button was clicked.\n");
}

t_element	*ui_create_button(t_window *win, t_xywh coord)
{
	t_element_info info;
	t_element	*elem;

	info = ft_default_elem_info(win, coord);
	info.info = (t_button *)malloc(sizeof(t_button));
	info.info_size = 0; // remove this in another iteration
	info.set_text = 1;
	// @Improvement: move this to set t_text or something liek that
	{
		info.text.x = 0;
		info.text.y = 5;
		info.text.text = "button";
		info.text.color = 0x000000;
		info.text.margin = 0;
		info.text.font = TTF_OpenFont("font.ttf", 28);
	}
	elem = ft_create_element(info);
	ft_add_element_to_window_elements(win, elem);
	return (elem);
}
