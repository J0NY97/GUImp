/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 19:15:07 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/12 11:00:09 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	pencil(SDL_Surface *surf, t_brush *brush, t_shapes l)
{

	if (brush->old_x == -1 && brush->old_y == -1)
	{
		l.fill = 1;
		ft_create_circle(surf, brush->color, l);
	}
	if (brush->old_x != -1 && brush->old_y != -1)
		ft_create_line(surf, brush->color, l);
}

void	set_sticker(SDL_Surface *surf, t_brush *brush, int x, int y)
{
	SDL_Rect temp;

	temp.h = 0;
	temp.w = 0;
	temp.x = x - (brush->stickers[brush->selected_sticker]->w / 2);
	temp.y = y - (brush->stickers[brush->selected_sticker]->h / 2);
	SDL_BlitSurface(brush->stickers[brush->selected_sticker], NULL, surf, &temp);
}

void	a_to_b_line(SDL_Surface *surf, t_brush *brush, t_shapes l)
{
	if (l.y2 != -1 && l.x2 != -1)
	{
		ft_create_line(surf, brush->color, l);
	}
}

void	draw(SDL_Event event, t_element *elem)
{
	t_shapes l;
	t_brush *brush;
	t_element **drawing_surfaces;
	SDL_Surface *surface;

	l.fill = 1;
	brush = (t_brush *)elem->extra_info;
	drawing_surfaces = ((t_surface *)elem->info)->extra;
	surface = drawing_surfaces[brush->selected_layer]->surface;
	l.x1 = event.button.x - elem->coord.x;
	l.y1 = event.button.y - elem->coord.y;
	l.size = brush->size;
	if (event.type == SDL_MOUSEBUTTONUP)
		brush->draw = 0;
	else if (event.type == SDL_MOUSEBUTTONDOWN)
		brush->draw = 1;
	if (brush->draw == 1)
	{
		l.x2 = brush->old_x;
		l.y2 = brush->old_y;
		if (brush->type == 1)
			pencil(surface, brush, l);
		else if (brush->type == 2)
			text_to_screen(surface, l, brush);
		else if (brush->type == 3)
		{
			brush->color = drawing_surfaces[brush->selected_layer]->bg_color;
			pencil(surface, brush, l);
		}
		else if (brush->type == 4) // flood
		{
			Uint32 targetColor = get_color(surface, l.x1, l.y1);
			flood_fill(surface, targetColor, brush->color, l.x1, l.y1);
		}
		else if (brush->type == 5)
		{
			set_sticker(surface, brush, l.x1, l.y1);
		}
		else if (brush->type == 6)
		{
			zoom_and_move(elem, event);
		}
		else if (brush->type == 7)
		{
			a_to_b_line(surface, brush, l);
		}
		else if (brush->type == 8) // pipette
		{
			brush->color = get_color(surface, l.x1, l.y1);
		}
		brush->old_x = l.x1;
		brush->old_y = l.y1;
	}
	else
	{
		brush->old_x = -1;
		brush->old_y = -1; //should be moved where brush type changes/button changes;
	}
}
