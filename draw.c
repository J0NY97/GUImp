/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 19:15:07 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/03 12:48:15 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	pencil(SDL_Surface *surf, t_brush *brush, t_shapes l)
{
	if (brush->old_x == -1 && brush->old_y == -1)
		ft_create_circle(surf, brush->color, l, 1);
	if (brush->old_x != -1 && brush->old_y != -1)
		ft_create_line(surf, brush->color, l);
}

void	draw(SDL_Event event, t_element *elem)
{
	t_shapes l;
	t_brush *brush;
	SDL_Surface *surface;

	brush = (t_brush *)elem->extra_info;
	surface = elem->surface;
	l.x2 = event.button.x - elem->coord.x;
	l.y2 = event.button.y - elem->coord.y;
	l.size = brush->size;
	if (event.type == SDL_MOUSEBUTTONUP)
		brush->draw = 0;
	else if (event.type == SDL_MOUSEBUTTONDOWN)
		brush->draw = 1;
	if (brush->draw == 1)
	{
		l.x1 = brush->old_x;
		l.y1 = brush->old_y;
		if (brush->type == 1)
			pencil(surface, brush, l);
		else if (brush->type == 2)
			text_to_screen(elem->surface, l, brush);
		else if (brush->type == 3)
		{
			brush->color = elem->bg_color;
			pencil(surface, brush, l);
		}
		else if (brush->type == 4)
		{
			Uint32 targetColor = get_color(elem->surface, l.x2, l.y2);
			flood_fill(elem->surface, targetColor, brush->color, l.x2, l.y2);
		}
		brush->old_x = l.x2;
		brush->old_y = l.y2;
	}
	else
	{
		brush->old_x = -1;
		brush->old_y = -1; //should be moved where brush type changes/button changes;
	}
}
