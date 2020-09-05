/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_create_drop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 16:47:20 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/05 14:24:29 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_element *ui_create_drop(t_window *win, t_xywh coord)
{
	t_element_info	info;
	t_element		*elem;

	info = ft_default_elem_info(win, coord, NULL);
	info.info = (t_drop_down *)malloc(sizeof(t_drop_down));
	info.info_size = 0;
	info.f = &ft_drop_down_function;
	info.set_text = 1;
	{
		info.text.x = 0;
		info.text.y = 0;
		info.text.text = "drip drawp";
		info.text.color = 0x000000;
		info.text.margin = 0;
		info.text.font = TTF_OpenFont("font.ttf", 32);
	}
	elem = ft_create_element(info);
	ft_add_element_to_window_elements(win, elem);
	// drop_down specific
	{
		t_drop_down *dd;

		dd = elem->info;
		//dd->items = NULL; // malloc here if you already know the max amount of items you want to add
		dd->item_amount = 0;
		dd->drop_height = (dd->item_amount + 1) * elem->coord.h;
		ft_update_drop(elem);
	}	
	return (elem);
}
