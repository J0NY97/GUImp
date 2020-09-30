/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 11:49:45 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/24 15:12:20 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_create_shadow(t_element *elem)
{
	SDL_Rect	temp;
	SDL_Surface	*shadow;
	t_shapes l;
	
	temp.w = elem->surface->w;	
	temp.h = elem->surface->h;
	l.fill = 1;
	l.color = 0xff9a9a9a;
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

	if (elem->parent_elem == NULL)
	{
		temp.x1 = ft_clamp(elem->coord.x, 0, elem->parent->w);
		temp.y1 = ft_clamp(elem->coord.y, 0, elem->parent->h);
		temp.x2 = ft_clamp(temp.x1 + elem->surface->w, 0, win->surface->w);
		temp.y2 = ft_clamp(temp.y1 + elem->surface->h, 0, win->surface->h);
		// this while loop is faster than the ft_create_square
		while (temp.x1 < temp.x2)
		{
			temp.y1 = ft_clamp(elem->coord.y, 0, elem->parent->h); // why this?
			while (temp.y1 < temp.y2)
			{
				set_pixel(win->surface, temp.x1, temp.y1,  win->bg_color);
				temp.y1++;
			}
			temp.x1++;
		}
	}
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
		SDL_BlitSurface(elem->surface, NULL, elem->parent_elem->surface, &temp);
	}
	else
		SDL_BlitSurface(elem->surface, NULL, win, &temp);
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
		ft_update_element(curr->content);
		curr = curr->next;
	}
}
