/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 11:49:45 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/09 17:29:15 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ui_clean(t_window *win, t_element *elem)
{
	SDL_Surface *black;
	SDL_Rect	temp;

	temp.x = elem->coord.x;
	temp.y = elem->coord.y;
	temp.w = elem->surface->w;
	temp.h = elem->surface->h;
	black = SDL_CreateRGBSurface(0, temp.w, temp.h, 32, 0, 0, 0, 0);
	if (elem->parent_elem != NULL)
	{
/*		temp.x = elem->rel_coord.x;
		temp.y = elem->rel_coord.y;
		ft_update_background(black, elem->parent_elem->bg_color);
		SDL_BlitSurface(black, NULL, elem->parent_elem->surface, &temp);*/
	}
	else
	{
		elem->old_state = 500;
		ft_update_element(elem);
		ft_update_background(black, win->bg_color);
		SDL_BlitSurface(black, NULL, win->surface, &temp);
	}
	SDL_FreeSurface(black);
}

void	ui_clean_elem(t_element *parent, t_element *elem)
{
	SDL_Surface *black;
	SDL_Rect	temp;

	temp.x = elem->coord.x;
	temp.y = elem->coord.y;
	temp.w = elem->surface->w;
	temp.h = elem->surface->h;
	black = SDL_CreateRGBSurface(0, temp.w, temp.h, 32, 0, 0, 0, 0);
	if (parent != NULL)
	{
		temp.x = elem->rel_coord.x;
		temp.y = elem->rel_coord.y;
		ft_update_background(black, elem->parent_elem->bg_color);
		SDL_BlitSurface(black, NULL, elem->parent_elem->surface, &temp);
	}
	SDL_FreeSurface(black);
}

/*
 ** Takes in a t_window and renders all its elements on it self; and then finally renders it self
*/

void	ui_render_element(SDL_Surface *win, t_element *elem)
{
	SDL_Rect temp;
	SDL_Rect s_temp;
	SDL_Surface *shadow;

	temp.x = elem->coord.x;
	temp.y = elem->coord.y;
	temp.w = elem->coord.w;
	temp.h = elem->coord.h;
//	if (elem->state == 1 && elem->parent_elem != NULL)
//		ui_clean_elem(elem->parent_elem, elem);
	if (elem->parent_elem != NULL)
	{
		temp.x = elem->rel_coord.x;//+ (elem->state == 1 ? 5 : 0);
		temp.y = elem->rel_coord.y;//+ (elem->state == 1 ? 5 : 0);
	//	temp.w = elem->rel_coord.w;
	//	temp.h = elem->rel_coord.h;
		temp.w = elem->surface->w;
		temp.h = elem->surface->h;
		ft_update_element(elem);
		// shadow
		s_temp.x = temp.x + 5;//+ (elem->state != 1 ? 5 : 0);
		s_temp.y = temp.y + 5;//+ (elem->state != 1 ? 5 : 0);
		s_temp.w = temp.w;
		s_temp.h = temp.h;
		shadow = SDL_CreateRGBSurface(0, temp.w, temp.h, 32, 0, 0, 0, 0);
		ft_update_background(shadow, 0x9a9a9a);
		SDL_BlitSurface(shadow, NULL, elem->parent_elem->surface, &s_temp);
		SDL_FreeSurface(shadow);
		// end shadow
		SDL_BlitSurface(elem->surface, NULL, elem->parent_elem->surface, &temp);
	}
	else
	{
		ft_update_element(elem);
		// shadow
		s_temp.x = temp.x + 5;
		s_temp.y = temp.y + 5;
		s_temp.w = temp.w;
		s_temp.h = temp.h;
		shadow = SDL_CreateRGBSurface(0, temp.w, temp.h, 32, 0, 0, 0, 0);
		ft_update_background(shadow, 0x9a9a9a);
		SDL_BlitSurface(shadow, NULL, win, &s_temp);
		SDL_FreeSurface(shadow);
		// end shadow
		SDL_BlitSurface(elem->surface, NULL, win, &temp);
	}
}

void	ui_recalc_elem(t_element *elem)
{
	if (elem->parent_elem != NULL)
	{
		elem->coord.x = elem->rel_coord.x + elem->parent_elem->coord.x;
		elem->coord.y = elem->rel_coord.y + elem->parent_elem->coord.y;
		elem->coord.w = elem->rel_coord.w;
		elem->coord.h = elem->rel_coord.h;
	}
	else
	{
		elem->coord = elem->rel_coord;
	}
}

void	ui_render(t_window *win)
{
	t_list *curr;

	curr = win->elements;
	while (curr != NULL)
	{
		ui_recalc_elem((t_element *)curr->content);
		ui_render_element(win->surface, (t_element *)curr->content);
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
