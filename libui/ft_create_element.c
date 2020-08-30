/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_button.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 12:07:14 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/30 19:18:35 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_element		*ft_create_element(t_element_info info)
{
	t_element *elem;

	if (!(elem = (t_element *)malloc(sizeof(t_element))))
		return (NULL);
	elem->coord = info.coord;
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
	if (info.f != NULL) // if you want an elem to call func every frame no matter what you have to put f to null and event_handler to the func
		elem->event_handler = &ft_event_handler;
	else
		elem->event_handler = info.event_handler;
	elem->statique = 0;
	elem->set_text = info.set_text;
	elem->text = info.text;
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
