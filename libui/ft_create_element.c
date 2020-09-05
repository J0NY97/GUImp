/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_button.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 12:07:14 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/05 13:30:53 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_element		*ft_create_element(t_element_info info)
{
	t_element *elem;

	if (!(elem = (t_element *)malloc(sizeof(t_element))))
		return (NULL);
	elem->rel_coord = info.rel_coord;
	elem->coord = ui_init_coords(0, 0, elem->rel_coord.w, elem->rel_coord.h);
	elem->bg_color = info.bg_color;
	if (info.info_size > 0)
	{
		elem->info = malloc(info.info_size);
		elem->info = ft_memcpy(elem->info, info.info, info.info_size);
	}
	else
		elem->info = info.info;
	elem->extra_info = info.extra_info;
	elem->f = info.f;
	elem->event_handler = info.event_handler;
	elem->statique = 0;
	elem->set_text = info.set_text;
	elem->text = info.text;
	elem->parent_elem = info.parent_elem;
	elem->parent = info.parent;
	elem->default_state = 0;
	elem->state = 0;
	elem->old_state = 500;
	elem->surface = SDL_CreateRGBSurface(0, elem->coord.w, elem->coord.h, 32, 0, 0, 0, 0);
	elem->states[0] = SDL_CreateRGBSurface(0, elem->coord.w, elem->coord.h, 32, 0, 0, 0, 0);
	ft_update_background(elem->states[0], elem->bg_color);
	elem->states[1] = SDL_CreateRGBSurface(0, elem->coord.w, elem->coord.h, 32, 0, 0, 0, 0);
	ft_update_background(elem->states[1], 0x0000ff);
	elem->states[2] = SDL_CreateRGBSurface(0, elem->coord.w, elem->coord.h, 32, 0, 0, 0, 0);
	ft_update_background(elem->states[2], 0x00ff00);
	ft_update_element(elem);
	return (elem);
}
