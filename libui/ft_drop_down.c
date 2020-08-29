/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drop_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:11:57 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/29 14:57:54 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_drop_down_add_item(t_element **drop, void (*f)(SDL_Event e, t_element *elem), char *name)
{
	t_drop_down *dd;
	t_element_info info;
	
	dd = (*drop)->info;
	if (dd->item_amount > 0) // if there is an item already from which it will take its new x and y, else take the dd menus
	{
		t_element *last_item;

		last_item = dd->items[dd->item_amount - 1];
		info.y = last_item->y + last_item->h;
	}
	else
		info.y = dd->height;
	info.x = 0;
	info.w = (*drop)->w;
	info.h = dd->height;	
	info.parent = (*drop)->surface; // this wont work because the surface of the parent will update everytime it is clicked
	info.bg_color = dd->item_amount % 2 == 0 ? 0xffffff : 0xd3d3d3;
	info.f = f;
	info.event_handler = &ft_mouse_button_handler;
	info.set_text = name != NULL;
	if (name != NULL)
	{
		info.text.x = 0;
		info.text.y = 0;
		info.text.text = ft_strdup(name);
		info.text.color = 0x000000;
		info.text.font = (*drop)->text.font;
	}
	dd->items[dd->item_amount] = ft_create_element(info);
	dd->item_amount += 1;
}
