/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_and_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 14:39:16 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/13 14:01:05 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	zoom_and_move(t_element *elem, SDL_Event event, int org_w, int org_h)
{
	int			w;
	int			h;
	t_brush		*brush;
	SDL_Surface	*surface;

	if (event.type == SDL_MOUSEWHEEL && event.wheel.y != 0)
	{
		brush = elem->extra_info;
		brush->zoom += event.wheel.y > 0 ? -10 : 10;
		h = ((org_w - brush->zoom) / ((float)org_w / (float)org_h));
		w = (h * ((float)org_w / (float)org_h));
		surface = SDL_CreateRGBSurface(0, w, h, 32, 
									0x00ff0000, 0x0000ff00,
									0x000000ff, 0xff000000);
		SDL_FreeSurface(elem->states[0]);
		elem->rel_coord.w = surface->w;
		elem->rel_coord.h = surface->h;
		elem->states[0] = surface;

	}
	else
	{
		elem->rel_coord.x = event.button.x - (elem->surface->w / 2);
		elem->rel_coord.y = event.button.y - (elem->surface->h / 2);
	}
}
