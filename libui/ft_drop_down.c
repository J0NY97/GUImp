/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drop_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:11:57 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/03 11:32:27 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_drop_down_add_item(t_element **drop, void (*f)(SDL_Event e, t_element *elem), char *name)
{
	t_drop_down *dd;
	t_element_info info;
	t_element *last_item;
	
	dd = (*drop)->info;
	info.coord = ui_init_coords((*drop)->coord.x, (*drop)->coord.y + (*drop)->coord.h, (*drop)->coord.w, (*drop)->coord.h);
	if (dd->item_amount > 0) // if there is an item already from which it will take its new x and y, else take the dd menus
	{
		last_item = dd->items[dd->item_amount - 1];
		info.coord.y = last_item->coord.y + last_item->coord.h;
	}
	info.info = (t_drop_item *)malloc(sizeof(t_drop_item));
	((t_drop_item *)info.info)->relative_coords = ui_init_coords(0, info.coord.y - (*drop)->coord.y, info.coord.w, info.coord.h);

	printf("actual y %d, relative y %d\n", info.coord.y, ((t_drop_item *)info.info)->relative_coords.y);

	info.info_size = 0;
	info.parent = (*drop)->parent; // this wont work because the surface of the parent will update everytime it is clicked
	info.bg_color = dd->item_amount % 2 == 0 ? 0xffffff : 0xd3d3d3;
	info.f = f;
	info.event_handler = &ft_event_handler;
	info.set_text = name != NULL;
	if (name != NULL)
	{
		info.text.x = 0;
		info.text.y = 0;
		info.text.text = ft_strdup(name);
		info.text.color = 0x000000;
		info.text.margin = 0;
		info.text.font = (*drop)->text.font;
	}
	dd->items[dd->item_amount] = ft_create_element(info);
	dd->item_amount += 1;
	ft_update_drop((*drop));
}
