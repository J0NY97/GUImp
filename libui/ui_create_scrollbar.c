/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_create_scrollbar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 10:55:09 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/19 12:20:20 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void		ft_set_scrollbar_value(t_element *elem, int value);
void		ft_update_scrollbar_bar(int click_x, int click_y, t_element *elem);
void		ft_scrollbar_function(SDL_Event e, t_element *elem);

t_element	*ui_create_scrollbar(t_window *win, t_element *parent)
{
	t_element_info	info;
	t_element		*elem;
	t_xywh			real;
	int				w;
	
	w = 25;
	real = ui_init_coords(parent->rel_coord.x + parent->rel_coord.w, parent->rel_coord.y, w, parent->rel_coord.h);
	parent->shadow = 0;
	info = ft_default_elem_info(win, real, parent->parent_elem);
	info.f = &ft_scrollbar_function;
	info.info = (t_slider *)malloc(sizeof(t_slider));
	info.info_size = 0;
	info.extra_info = parent;
	elem = ft_create_element(info);
	ft_add_element_to_window_elements(win, elem);
	{
		((t_slider *)elem->info)->min = -(parent->coord.h / 2);
		((t_slider *)elem->info)->max = (parent->coord.h / 2);
		((t_slider *)elem->info)->value = 0;
		((t_slider *)elem->info)->bar_color = 0xffd3d3d3;
	}
	ft_set_scrollbar_value(elem, ((t_slider *)elem->info)->value);
	return (elem);
}

void		ft_set_scrollbar_value(t_element *elem, int new_value)
{
	t_slider	*slider;
	int			bar_y;
	int			diff;
	float		ppv;

	slider = elem->info;
	slider->value = new_value;
	{
		diff = slider->min - slider->max;
		diff = diff < 0 ? -diff : diff;
		diff = diff == 0 ? 1 : diff;
	}
	ppv = ((float)elem->coord.h / (float)diff);
	bar_y = (ppv) * (slider->max - slider->value);
	ft_update_scrollbar_bar(0, bar_y + elem->coord.y, elem);
}

void		ft_update_scrollbar_bar(int click_x, int click_y, t_element *elem)
{
	SDL_Surface *bar;
	SDL_Rect	temp;
	t_slider	*slider;
	float		ppv;
	int			diff;
	int			x;
	int			y;

	slider = (t_slider *)elem->info;
	x = click_x - elem->coord.x;
	y = click_y - elem->coord.y;
	bar = ft_create_rgba_surface(elem->coord.w, 10);
	ft_update_background(elem->states[0], elem->bg_color);
	ft_update_background(elem->states[1], elem->bg_color);
	ft_update_background(elem->states[2], elem->bg_color);
	ft_update_background(bar, slider->bar_color);
	{
		diff = slider->min - slider->max;
		diff = diff < 0 ? -diff : diff;
		diff = diff == 0 ? 1 : diff;
	}
	ppv = (float)elem->coord.h / (float)diff;
	temp.x = 0;
	temp.y = y - (bar->h / 2);
	temp.w = bar->w;
	temp.h = bar->h;
	SDL_BlitSurface(bar, NULL, elem->states[0], &temp);
	SDL_BlitSurface(bar, NULL, elem->states[1], &temp);
	SDL_BlitSurface(bar, NULL, elem->states[2], &temp);
	slider->value = y / ppv - slider->max;
	SDL_FreeSurface(bar);
}

void		ft_scrollbar_function(SDL_Event e, t_element *elem)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
		elem->state = 1;
	if (e.type == SDL_MOUSEMOTION && elem->state == 1)
		elem->state = 2;
	if (e.type == SDL_MOUSEBUTTONUP)
		elem->state = 0;
	if (elem->state == 1 || elem->state == 2)
	{
		ft_update_scrollbar_bar(0, e.button.y, elem);
		((t_element *)elem->extra_info)->offset_y = ((t_slider *)elem->info)->value;
	}
}
