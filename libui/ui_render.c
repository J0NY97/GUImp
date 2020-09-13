/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 11:49:45 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/13 18:20:38 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"
#include "time.h"

void	ui_create_shadow(t_element *elem)
{
	SDL_Rect	temp;
	SDL_Surface	*shadow;
	t_shapes l;
	
	temp.w = elem->surface->w;	
	temp.h = elem->surface->h;
	if (elem->parent_elem != NULL)
	{
		temp.x = elem->rel_coord.x;
		temp.y = elem->rel_coord.y;
	}
	else
	{
		temp.x = elem->coord.x;
		temp.y = elem->coord.y;
	}
	l.x1 = temp.x + temp.w;
	l.y1 = temp.y + 5;
	l.x2 = l.x1 + 5;
	l.y2 = l.y1 + temp.h;
	l.fill = 1;
	l.color = 0xff9a9a9a;
	if (elem->parent_elem)
		ft_create_square(elem->parent_elem->surface, 0xff9a9a9a, l);
	else
		ft_create_square(elem->parent, 0xff9a9a9a, l);
	l.x1 = temp.x + 5;
	l.x2 = l.x1 + temp.w;
	l.y1 = temp.y + temp.h;
	l.y2 = l.y1 + 5;
	if (elem->parent_elem)
		ft_create_square(elem->parent_elem->surface, 0xff9a9a9a, l);
	else
		ft_create_square(elem->parent, 0xff9a9a9a, l);
}

void	ui_clean(t_window *win, t_element *elem)
{
	t_shapes	temp;

	temp.x1 = elem->coord.x;
	temp.y1 = elem->coord.y;
	temp.x2 = temp.x1 + elem->surface->w;
	temp.y2 = temp.y1 + elem->surface->h;
	ft_create_square(win->surface, win->bg_color, temp);
	elem->old_state = 365;
	ft_update_element(elem);
}

void	ui_render_element(SDL_Surface *win, t_element *elem)
{
	SDL_Rect temp;
	SDL_Surface *shadow;

	temp.x = elem->coord.x;
	temp.y = elem->coord.y;
	temp.w = elem->surface->w;
	temp.h = elem->surface->h;
	if (elem->shadow)
		ui_create_shadow(elem);
	if (elem->parent_elem != NULL)
	{
		temp.x = elem->rel_coord.x + elem->offset_x;
		temp.y = elem->rel_coord.y + elem->offset_y;
		ft_update_element(elem);
		SDL_BlitSurface(elem->surface, NULL, elem->parent_elem->surface, &temp);
	}
	else
	{
		ft_update_element(elem);
		SDL_BlitSurface(elem->surface, NULL, win, &temp);
	}
}

void	ui_recalc_elem(t_element *elem)
{
	elem->coord = elem->rel_coord;
	elem->coord.w = elem->surface->w;
	elem->coord.h = elem->surface->h;
	elem->coord.x += elem->offset_x;
	elem->coord.y += elem->offset_y;
	if (elem->parent_elem != NULL)
	{
		elem->coord.x += elem->parent_elem->coord.x;
		elem->coord.y += elem->parent_elem->coord.y;
	}
}

void	ui_render(t_window *win)
{
	t_list *curr;
	t_element *elem;
	
	curr = win->elements;
	while (curr != NULL)
	{
		elem = curr->content;
		ui_recalc_elem(elem);
		ui_render_element(win->surface, elem);
		curr = curr->next;
	}
	SDL_UpdateWindowSurface(win->win);
	curr = win->elements;
	while (curr != NULL)
	{
		ui_clean(win, curr->content);
		curr = curr->next;
	}
}
