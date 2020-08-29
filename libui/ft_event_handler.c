/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_button_handler.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:35:47 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/29 17:58:17 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int		ft_event_handler(t_libui *libui, t_element *elem)
{
	int x;
	int y;

	x = libui->event.button.x;
	y = libui->event.button.y;
	if ((x >= elem->x && y >= elem->y &&
		x <= elem->x + elem->w && y <= elem->y + elem->h)
		|| libui->event.type == SDL_MOUSEWHEEL)
	{
		elem->f(libui->event, elem);
		return (1);
	}
	return (0);
}
