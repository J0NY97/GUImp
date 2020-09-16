/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_button.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 12:07:14 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/16 11:34:51 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_element		*ft_create_element(t_element_info info)
{
	t_element *elem;

	if (!(elem = (t_element *)malloc(sizeof(t_element))))
		return (NULL);
	elem->parent_elem = info.parent_elem;
	elem->rel_coord = info.rel_coord;
	elem->coord = info.rel_coord;
	if (elem->parent_elem != NULL)
	{
		elem->coord.x += elem->parent_elem->coord.x;
		elem->coord.y += elem->parent_elem->coord.y;	
	}
	if (info.info_size > 0)
	{
		elem->info = malloc(info.info_size);
		elem->info = ft_memcpy(elem->info, info.info, info.info_size);
	}
	else
		elem->info = info.info;
	elem->shadow = info.shadow;
	elem->bg_color = info.bg_color;
	elem->extra_info = info.extra_info;
	elem->f = info.f;
	elem->event_handler = info.event_handler;
	elem->statique = 0;
	elem->set_text = info.set_text;
	elem->text = info.text;
	elem->default_state = 0;
	elem->state = 0;
	elem->loop = 0;
	elem->offset_x = 0;
	elem->offset_y = 0;
	elem->parent = info.parent;
	elem->surface = ft_create_rgba_surface(elem->coord.w, elem->coord.h);
	elem->states[0] = ft_create_rgba_surface(elem->coord.w, elem->coord.h);
	ft_update_background(elem->states[0], elem->bg_color);
	elem->states[1] = ft_create_rgba_surface(elem->coord.w, elem->coord.h);
	ft_update_background(elem->states[1], 0xff0000ff);
	elem->states[2] = ft_create_rgba_surface(elem->coord.w, elem->coord.h);
	ft_update_background(elem->states[2], 0xff00ff00);
	ft_update_element(elem);
	return (elem);
}
