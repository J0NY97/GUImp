/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_button_handler.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:35:47 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/02 15:57:34 by jsalmi           ###   ########.fr       */
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

int		ft_keyboard_handler(t_libui *libui)
{
	t_list *lst;
	t_hotkey *hk;
	SDL_Event e;

	e = libui->event;
	if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP)
	{
		lst = libui->hotkeys;
		while (lst != NULL)
		{
			hk = (t_hotkey *)lst->content;
			if (hk->key == e.key.keysym.sym)
			{
				hk->f(libui->event, hk);
				return (1);
			}
			lst = lst->next;
		}
	}
	return (0);
}
