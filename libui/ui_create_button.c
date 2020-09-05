/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_create_button.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 11:04:46 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/05 16:15:50 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void		default_click(SDL_Event e, t_element *elem)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
		ft_putstr("A button was clicked.\n");
}

t_element	*ui_create_button(t_window *win, t_xywh rel_coord, t_element *parent)
{
	t_element_info info;
	t_element	*elem;

	info = ft_default_elem_info(win, rel_coord, parent);
	info.info = (t_button *)malloc(sizeof(t_button));
	info.info_size = 0; // remove this in another iteration
	info.set_text = 1;
	info.text = ft_default_text("button");
	elem = ft_create_element(info);
	ft_add_element_to_window_elements(win, elem);
	return (elem);
}
