/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_button_handler.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:35:47 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/30 18:35:16 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int		ft_event_handler(t_libui *libui, t_element *elem)
{
	int x;
	int y;

	x = libui->event.button.x;
	y = libui->event.button.y;
	if ((x >= elem->coord.x && y >= elem->coord.y &&
		x <= elem->coord.x + elem->coord.w && y <= elem->coord.y + elem->coord.h)
		|| libui->event.type == SDL_MOUSEWHEEL)
	{
		elem->f(libui->event, elem);
		return (1);
	}
	elem->state = elem->default_state;
	return (0);
}
