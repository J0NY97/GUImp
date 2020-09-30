/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 19:15:07 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/30 15:14:52 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

static inline void	pencil(SDL_Surface *surf, t_brush *brush, Uint32 color)
{
	if (brush->shape.x2 == -1 && brush->shape.y2 == -1)
		ft_create_circle(surf, color, brush->shape);
	if (brush->shape.x2 != -1 && brush->shape.y2 != -1)
		ft_create_line(surf, color, brush->shape);
}

static inline void	set_sticker(SDL_Surface *surf, t_brush *brush)
{
	SDL_Rect temp;

	temp.h = 0;
	temp.w = 0;
	temp.x = brush->shape.x1 -
		(brush->stickers[brush->selected_sticker]->w / 2);
	temp.y = brush->shape.y1 -
		(brush->stickers[brush->selected_sticker]->h / 2);
	SDL_BlitSurface(brush->stickers[brush->selected_sticker],
			NULL, surf, &temp);
}

static inline void	activate_draw(SDL_Surface *surface, t_brush *brush)
{
	if (brush->type == 1)
		pencil(surface, brush, brush->color);
	else if (brush->type == 2)
		text_to_screen(surface, brush->shape, brush->str, brush->font_dir);
	else if (brush->type == 4)
		flood_fill(surface, get_color(surface, brush->shape.x1,
			brush->shape.y1), brush->color, brush->shape.x1, brush->shape.y1);
	else if (brush->type == 5)
		set_sticker(surface, brush);
	else if (brush->type == 7)
		return (select_shape(surface, brush));
	else if (brush->type == 8)
		brush->color = get_color(surface, brush->shape.x1, brush->shape.y1);
	brush->shape.x2 = brush->shape.x1;
	brush->shape.y2 = brush->shape.y1;
}

static inline void	deactivate_draw(SDL_Surface *surface, t_brush *brush)
{
	if (brush->type == 7 && brush->shape.x2 != -1 && brush->shape.y2 != -1)
	{
		brush->shape.fill = 0;
		if (brush->shape_type == 1)
		{
			brush->shape.size = POS(brush->shape.y1 - brush->shape.y2) +
								POS(brush->shape.x1 - brush->shape.x2);
			ft_create_circle(surface, brush->color, brush->shape);
		}
		else if (brush->shape_type == 2)
			ft_create_square(surface, brush->color, brush->shape);
		else if (brush->shape_type == 3)
			ft_create_line(surface, brush->color, brush->shape);
	}
	brush->shape.x2 = -1;
	brush->shape.y2 = -1;
}

void				draw(SDL_Event event, t_element *elem)
{
	t_brush		*brush;
	t_element	**drawing_surfaces;
	SDL_Surface	*surface;

	drawing_surfaces = ((t_surface *)elem->info)->extra;
	brush = (t_brush *)elem->extra_info;
	brush->shape.fill = 1;
	brush->shape.size = brush->size;
	surface = drawing_surfaces[brush->selected_layer]->surface;
	brush->aspect_x = ((float)surface->w / (float)elem->surface->w);
	brush->aspect_y = ((float)surface->h / (float)elem->surface->h);
	brush->shape.x1 = (event.button.x - elem->coord.x) * brush->aspect_x;
	brush->shape.y1 = (event.button.y - elem->coord.y) * brush->aspect_y;
	if (event.type == SDL_MOUSEBUTTONUP)
		brush->draw = 0;
	else if (event.type == SDL_MOUSEBUTTONDOWN)
		brush->draw = 1;
	if (brush->draw == 1 && brush->type == 3)
		pencil(surface, brush,
			drawing_surfaces[brush->selected_layer]->bg_color);
	else if (brush->draw == 1 && brush->type == 6)
		zoom_and_move(elem, event, surface->w, surface->h);
	else
		brush->draw == 1 ? activate_draw(surface, brush) :
			deactivate_draw(surface, brush);
}
