/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drop_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:11:57 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/19 11:13:47 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_drop_down_add_item(t_window *win, t_element *drop, char *name)
{
	t_drop_down *dd;
	t_element_info new_item;
	t_element *last_item;
	
	dd = drop->info;
	new_item.rel_coord = ui_init_coords(0, drop->coord.h, drop->coord.w, drop->coord.h);
	if (dd->item_amount > 0) // if there is an item already from which it will take its new x and y, else take the dd menus
	{
		last_item = dd->items[dd->item_amount - 1];
		new_item.rel_coord.y = last_item->rel_coord.y + last_item->rel_coord.h;
	}
	new_item.info = (t_drop_item *)malloc(sizeof(t_drop_item));
	new_item.info_size = 0;
	new_item.extra_info = dd->items;
	new_item.parent_elem = drop;
	new_item.parent = drop->parent;
	new_item.bg_color = dd->item_amount % 2 == 0 ? 0xffffffff : 0xffd3d3d3;
	new_item.f = &ft_drop_item_function;
	new_item.event_handler = &ft_event_handler;
	((t_drop_item *)new_item.info)->item_nbr = dd->item_amount;
	dd->items[dd->item_amount] = ft_create_element(new_item);
	if (name != NULL)
	{
		dd->items[dd->item_amount]->text.set_text = 1;
		ft_set_text(&dd->items[dd->item_amount]->text, name);
	}
	ft_add_to_non_render_elem_list(win, dd->items[dd->item_amount]);
	dd->item_amount += 1;
	ft_update_drop(drop);
}
