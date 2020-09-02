/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_poller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:16:58 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/02 16:17:07 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	call_all_element_event_handlers(t_libui *libui, t_window *win)
{
	t_list *curr;
	t_element *elem;

	curr = win->elements;
	while (curr != NULL)
	{
		elem = curr->content;
		elem->event_handler(libui, elem);
		curr = curr->next;
	}
}

void	ft_event_poller(t_libui *libui)
{
	t_list *win;

	SDL_PollEvent(&libui->event);
	{
		if (libui->event.type == SDL_QUIT)
			exit (1);
		if (libui->event.type == SDL_WINDOWEVENT && libui->event.window.event == SDL_WINDOWEVENT_CLOSE)
			exit (1);
		if (libui->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			exit (1);
		win = libui->windows;
		while (win != NULL)
		{
			if (((t_window *)win->content)->id == libui->event.window.windowID)
				call_all_element_event_handlers(libui, win->content);
			win = win->next;
		}
		ft_keyboard_handler(libui);
	}
}
