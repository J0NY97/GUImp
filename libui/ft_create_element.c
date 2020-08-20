/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_button.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 12:07:14 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/20 12:57:16 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_element		*ft_create_element(t_element_info info)
{
	t_element *elem;

	if (!(elem = (t_element *)malloc(sizeof(t_element))))
	{
		ft_putstr("[create_element] Couldnt malloc new element.\n");
		return (NULL);
	}
	elem->x = info.x;
	elem->y = info.y;
	elem->w = info.w;
	elem->h = info.h;
	elem->bg_color = info.bg_color;
	elem->info = info.info;
	elem->f = info.f;
	elem->event_handler = info.event_handler;
	elem->text_info = info.text_info;
	elem->parent = info.parent;
	
	ft_update_element(elem);	
	return (elem);
}
