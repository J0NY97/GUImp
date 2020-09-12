/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 19:15:07 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/12 14:00:51 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"
#define POS(n) ((n) < 0 ? 0 - (n) : (n))

void	pencil(SDL_Surface *surf, t_brush *brush, Uint32 color)
{
	t_shapes l;

	l = brush->shape;
	if (l.x2 == -1 &&  l.y2 == -1)
	{
		l.fill = 1;
		ft_create_circle(surf, color, l);
	}
	if (l.x2 != -1 &&  l.y2 != -1)
		ft_create_line(surf, color, l);
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

void	select_shape(SDL_Surface *surf, t_brush *brush)
{
	t_shapes l;

	l = brush->shape;
	if (l.x2 != -1 && l.y2 != -1)
	{
		if (brush->shape_type == 1)
		{
			l.fill = 0;
			l.size = POS(l.y1 - l.y2) + POS(l.x1 - l.x2); 
			ft_create_circle(surf, brush->color, l);
		}
		else if (brush->shape_type == 2)
		{
			l.fill = 0;
			ft_create_square(surf, brush->color, l);
		}
		else if (brush->shape_type == 3)
			ft_create_line(surf, brush->color, l);	
		else if (brush->shape_type == 4)
		{
			l.size = POS(l.y1 - l.y2) + POS(l.x1 - l.x2); 
			ft_create_circle(surf, brush->color, l);
		}
		else if (brush->shape_type == 5)
			ft_create_square(surf, brush->color, l);
	}
}

void	draw(SDL_Event event, t_element *elem)
{
	t_brush		*brush;
	SDL_Surface	*surface;
	t_element	**drawing_surfaces;

	drawing_surfaces = ((t_surface *)elem->info)->extra;
	brush = (t_brush *)elem->extra_info;
	brush->shape.fill = 1;
	brush->shape.x1 = event.button.x - elem->coord.x;
	brush->shape.y1 = event.button.y - elem->coord.y;
	brush->shape.size = brush->size;
	surface = drawing_surfaces[brush->selected_layer]->surface;
	if (event.type == SDL_MOUSEBUTTONUP)
		brush->draw = 0;
	else if (event.type == SDL_MOUSEBUTTONDOWN)
		brush->draw = 1;
	if (brush->draw == 1)
	{
		if (brush->type == 1)
			pencil(surface, brush, brush->color);
		else if (brush->type == 2)
			text_to_screen(surface, brush->shape, brush);
		else if (brush->type == 3)
			pencil(surface, brush, drawing_surfaces[brush->selected_layer]->bg_color);
		else if (brush->type == 4) // flood
		{
			flood_fill(surface, get_color(surface, brush->shape.x1, brush->shape.y1),
						brush->color, brush->shape.x1, brush->shape.y1);
		}
		else if (brush->type == 5)
		{
			set_sticker(surface, brush, brush->shape.x1, brush->shape.y1);
		}
		else if (brush->type == 6)
		{
			zoom_and_move(elem, event);
		}
		else if (brush->type == 7)
		{
			select_shape(surface, brush);
		}
		else if (brush->type == 8) // pipette
		{
			brush->color = get_color(surface, brush->shape.x1, brush->shape.y1);
		}
		brush->shape.x2 = brush->shape.x1;
		brush->shape.y2 = brush->shape.y1;
	}
	else if (brush->draw == 0)
	{
		brush->shape.x2 = -1;
		brush->shape.y2 = -1;
	}
}
