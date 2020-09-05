/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drop_down_function.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 16:54:31 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/05 16:26:18 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

// this should be called when new item is added to the drop menu
void	ft_update_drop(t_element *elem)
{
	t_drop_down *dd;

	dd = elem->info;
	SDL_FreeSurface(elem->states[1]);
	dd->drop_height = (dd->item_amount + 1) * elem->coord.h;
	elem->states[1] = SDL_CreateRGBSurface(0, elem->coord.w, dd->drop_height, 32, 0, 0, 0, 0);
	ft_update_background(elem->states[1], 0x00ff00);
	printf("drop height %d\n", dd->drop_height);	
	for (int i = 0; i < dd->item_amount; i++)
	{
		t_element *item;
		SDL_Rect	temp;

		item = dd->items[i];
		temp.x = item->rel_coord.x;
		temp.y = item->rel_coord.y;
		temp.w = item->coord.w;
		temp.h = item->coord.h;
		printf("x %d, y %d, w %d, h %d\n", temp.x, temp.y, temp.w, temp.h);
		SDL_BlitSurface(item->surface, NULL, elem->states[1], &temp);
	}
}

void	ft_drop_down_function(SDL_Event e, t_element *elem)
{
	t_drop_down *dd;

	dd = elem->info;
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (elem->state == 1)
		{
			printf("clicked %d %d\n", e.button.x, e.button.y);
			for (int i = 0; i < dd->item_amount; i++)
			{
				dd->items[i]->event_handler(e, dd->items[i]);
			}
		}
		if (elem->state == 0)
		{
			elem->coord.h = dd->drop_height;
			elem->state = 1;
			elem->default_state = 1;
		}
		else if (elem->state == 1)
		{
			elem->coord.h = dd->height;
			elem->state = 0;
			elem->default_state = 0;
		}
		printf("drop coords: %d %d %d %d\n", elem->coord.x, elem->coord.y, elem->coord.w, elem->coord.h);
	}
}
