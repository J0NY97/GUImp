/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drop_down_function.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 16:54:31 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/16 17:22:47 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_drop_item_function(SDL_Event e, t_element *elem)
{
	t_element **items;
	t_drop_down *dd;

	dd = elem->parent_elem->info;
	items = dd->items;
	for (int i = 0; i < dd->item_amount; i++)
	{
		dd->items[i]->state = 0;
		ft_update_element(dd->items[i]);
	}
	elem->state = 1;
	ft_update_element(elem);
	ft_update_drop(elem->parent_elem);
}

// this should be called when new item is added to the drop menu
void	ft_update_drop(t_element *elem)
{
	t_drop_down *dd;
	t_element *item;
	SDL_Rect	temp;

	dd = elem->info;
	SDL_FreeSurface(elem->states[1]);
	dd->drop_height = (dd->item_amount + 1) * dd->height;
	elem->states[1] = ft_create_rgba_surface(elem->coord.w, dd->drop_height);
	ft_update_background(elem->states[1], 0xff00ff00);
	for (int i = 0; i < dd->item_amount; i++)
	{
		item = dd->items[i];
		temp.x = item->rel_coord.x;
		temp.y = item->rel_coord.y;
		temp.w = item->rel_coord.w;
		temp.h = item->rel_coord.h;
		ft_update_element(dd->items[i]);
		SDL_BlitSurface(item->surface, NULL, elem->states[1], &temp);
	}
}

void	ft_drop_down_function(SDL_Event e, t_element *elem)
{
	t_drop_down *dd;
	SDL_Rect temp;

	dd = elem->info;
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (elem->state == 1)
			for (int i = 0; i < dd->item_amount; i++)
				dd->items[i]->event_handler(e, dd->items[i]);
		if (elem->state == 0)
		{
			elem->coord.h = dd->drop_height;
			elem->rel_coord.h = dd->drop_height;
			elem->state = 1;
			elem->default_state = 1;
		}
		else if (elem->state == 1)
		{
			elem->coord.h = dd->height;
			elem->rel_coord.h = dd->height;
			elem->state = 0;
			elem->default_state = 0;
		}
	}
}
