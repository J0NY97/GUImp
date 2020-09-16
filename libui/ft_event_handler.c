/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_button_handler.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:35:47 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/16 16:47:45 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int		ft_event_handler(SDL_Event e, t_element *elem)
{
	int x;
	int y;

	x = e.button.x;
	y = e.button.y;
	if ((x >= elem->coord.x && y >= elem->coord.y &&
		x <= elem->coord.x + elem->surface->w && y <= elem->coord.y + elem->surface->h)
		|| e.type == SDL_MOUSEWHEEL)
	{
		if (elem->f)
			elem->f(e, elem);
		return (1);
	}
	else if (elem->loop == 1)
	{
		if (elem->f)
			elem->f(e, elem);
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
	if (e.type == SDL_KEYDOWN)
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
