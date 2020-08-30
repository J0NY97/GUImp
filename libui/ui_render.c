/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 11:49:45 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/30 15:23:08 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

/*
 ** Takes in a t_window and renders all its elements on it self; and then finally renders it self
*/

void	ui_render_element(SDL_Surface *win, t_element *elem)
{
	SDL_Rect temp;

	temp.x = elem->x;
	temp.y = elem->y;
	temp.w = elem->w;
	temp.h = elem->h;
	ft_update_element(elem);
	SDL_BlitSurface(elem->surface, NULL, win, &temp);
}

void	ui_render(t_window *win)
{
	t_list *curr;

	curr = win->elements;
	while (curr != NULL)
	{
		ui_render_element(win->surface, (t_element *)curr->content);
		curr = curr->next;
	}
	SDL_UpdateWindowSurface(win->win);
}
