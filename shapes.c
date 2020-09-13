/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 16:02:35 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/13 16:46:08 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	trace_shape(t_info *info)
{
	float w;
	float h;
	t_shapes l;

	if (info->brush.draw && info->brush.shape.x2 != -1 && info->brush.shape.y2 != -1)
	{
		l = info->brush.shape;
		w = ((float)info->drawing_surface[0]->surface->w / (float)info->screen_surface->surface->w);
		h = ((float)info->drawing_surface[0]->surface->h / (float)info->screen_surface->surface->h);
		l.x1 = info->brush.shape.x1 / w + info->screen_surface->coord.x;
		l.y1 = info->brush.shape.y1 / h + info->screen_surface->coord.y;
		l.x2 = info->brush.shape.x2 / w + info->screen_surface->coord.x;
		l.y2 = info->brush.shape.y2 / h + info->screen_surface->coord.y;
		if (info->brush.shape_type == 1)
		{
			l.size = POS(l.y1 - l.y2) + POS(l.x1 - l.x2);
			ft_create_circle(info->hidden_surface->surface, info->brush.color, l);
		}
		else if (info->brush.shape_type == 2)
			ft_create_square(info->hidden_surface->surface, info->brush.color, l);
		else if (info->brush.shape_type == 3)
			ft_create_line(info->hidden_surface->surface, info->brush.color, l);
	}
}

void	select_shape(SDL_Surface *surf, t_brush *brush)
{
	t_shapes *l;

	l = &brush->shape;
	if (l->x2 != -1 && l->y2 != -1)
	{
		l->fill = 0;
		if (brush->shape_type == 1)
			l->size = POS(l->y1 - l->y2) + POS(l->x1 - l->x2);
		else if (brush->shape_type == 3)
			l->fill = 1;
	}
	else
	{
		brush->shape.x2 = brush->shape.x1;
		brush->shape.y2 = brush->shape.y1;
	}
}
