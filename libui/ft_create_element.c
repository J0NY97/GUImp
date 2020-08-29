/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_button.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 12:07:14 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/29 18:23:40 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_element		*ft_create_element(t_element_info info)
{
	t_element *elem;

	if (!(elem = (t_element *)malloc(sizeof(t_element))))
		return (NULL);
	elem->x = info.x;
	elem->y = info.y;
	elem->w = info.w;
	elem->h = info.h;
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
	elem->set_text = info.set_text;
	elem->text = info.text;
	elem->parent = info.parent;
	elem->surface = SDL_CreateRGBSurface(0, elem->w, elem->h, 32, 0, 0, 0, 0);
	ft_update_element(elem);	
	return (elem);
}
