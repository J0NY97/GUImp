/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_create_drop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 16:47:20 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/17 12:32:50 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_element *ui_create_drop(t_window *win, t_xywh rel_coord, t_element *parent)
{
	t_element_info	info;
	t_element		*elem;
	t_drop_down 	*dd;

	info = ft_default_elem_info(win, rel_coord, parent);
	info.info = (t_drop_down *)malloc(sizeof(t_drop_down));
	info.info_size = 0;
	info.f = &ft_drop_down_function;
	elem = ft_create_element(info);
	ft_add_element_to_window_elements(win, elem);
	{
		dd = elem->info;
		//dd->items = NULL; // malloc here if you already know the max amount of items you want to add
		dd->item_amount = 0;
		dd->height = elem->coord.h;
		dd->drop_height = (dd->item_amount + 1) * elem->coord.h;
		ft_update_drop(elem);
	}	
	return (elem);
}
