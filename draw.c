/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 19:15:07 by nneronin          #+#    #+#             */
/*   Updated: 2020/08/23 13:40:59 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	draw(SDL_Event event, t_element *elem)
{
	t_shapes l;
	t_brush *brush;
	int x;
	int y;

	brush = (t_brush *)elem->info;
	x = event.button.x - elem->x;
	y = event.button.y - elem->y;
	l.size = brush->size;
	if (event.type == SDL_MOUSEBUTTONUP)
		brush->draw = 0;
	else if (event.type == SDL_MOUSEBUTTONDOWN)
		brush->draw = 1;
	if (brush->draw == 1)
	{
		l.x2 = x;
		l.y2 = y;
		l.x1 = brush->old_x;
		l.y1 = brush->old_y;
		if (brush->old_x == -1 && brush->old_y == -1)
			ft_create_circle(elem->surface, brush->color, l, 1);
		if (brush->old_x != -1 && brush->old_y != -1)
			ft_create_line(elem->surface, brush->color, l);
		brush->old_x = x;
		brush->old_y = y;
	}
	else
	{
		brush->old_x = -1;
		brush->old_y = -1;
	}
//		set_pixel(elem->surface, event.button.x - elem->x, event.button.y - elem->y, 0xff0000);
}
