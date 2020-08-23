/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 19:15:07 by nneronin          #+#    #+#             */
/*   Updated: 2020/08/23 14:15:04 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	draw(SDL_Event event, t_element *elem)
{
	t_line l;
	t_brush *brush;
	t_circle c;
	int x;
	int y;

	brush = (t_brush *)elem->info;
	x = event.button.x - elem->x;
	y = event.button.y - elem->y;
	c.r = brush->size;
	c.xc = x;
	c.yc = y;
	if (event.type == SDL_MOUSEBUTTONUP)
		brush->draw = 0;
	else if (event.type == SDL_MOUSEBUTTONDOWN)
		brush->draw = 1;
	if (brush->draw == 1)
	{
		if (brush->type == 1)
			if (brush->old_x == -1 && brush->old_y == -1)
				ft_create_circle(elem->surface, brush->color, c, 1);
		if (brush->type == 2)
		{}
		if (brush->type == 3)
		{}
		if (brush->type == 4)
		{
			Uint32 targetColor = get_color(elem->surface, x, y);
			flood_fill(elem->surface, targetColor, brush->color, x, y);
			return ;
		}
		l.y2 = y;
		l.x2 = x;
		l.x1 = brush->old_x;
		l.y1 = brush->old_y;
		if (brush->old_x != -1 && brush->old_y != -1)
			ft_create_line(elem->surface, brush->color, brush->size, &l);
		brush->old_x = x;
		brush->old_y = y;
	}
	else
	{
		brush->old_x = -1;
		brush->old_y = -1;
	}
}
