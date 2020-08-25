/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 19:15:07 by nneronin          #+#    #+#             */
/*   Updated: 2020/08/25 15:28:23 by nneronin         ###   ########.fr       */
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

	brush = (t_brush *)elem->info;
	l.x2 = event.button.x - elem->x;
	l.y2 = event.button.y - elem->y;
	l.size = brush->size;
	if (event.type == SDL_MOUSEBUTTONUP)
		brush->draw = 0;
	else if (event.type == SDL_MOUSEBUTTONDOWN)
		brush->draw = 1;
	if (brush->draw == 1)
	{
		if (brush->type == 1)
			pencil(elem->surface, brush, l);
		if (brush->type == 2)
		{}
		if (brush->type == 3)
		{}
		if (brush->type == 4)
		{
			Uint32 targetColor = get_color(elem->surface, l.x2, l.y2);
			flood_fill(elem->surface, targetColor, brush->color, l.x2, l.y2);
			return ;
		}
		brush->old_x = x;
		brush->old_y = y;
	}
	else
	{
		brush->old_x = -1;
		brush->old_y = -1; //should be moved where brush type changes/button changes;
	}
}
