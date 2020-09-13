/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_and_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 14:39:16 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/13 13:32:14 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

#define E_SURF_W elem->surface->w
#define E_SURF_H elem->surface->h

void	zoom_and_move(t_element *elem, SDL_Event event, int org_w, int org_h)
{
	int			w;
	int			h;
	t_brush		*brush;
	SDL_Surface	*surf;

	if (event.type == SDL_MOUSEWHEEL && event.wheel.y != 0)
	{
		brush = elem->extra_info;
		brush->zoom += event.wheel.y > 0 ? -10 : 10;
		brush->aspect = ((float)org_w / (float)org_h);

		h = ((org_w - brush->zoom) / brush->aspect);
		w = (h * brush->aspect);

		printf("W: %d, H: %d\n", w, h);

		surf = SDL_CreateRGBSurface(0, w, h, 32,
				0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
		SDL_FreeSurface(elem->states[0]);
		elem->rel_coord.w = surf->w;
		elem->rel_coord.h = surf->h;
		elem->states[0] = surf;

	}
	else
	{
		elem->rel_coord.x = event.button.x - (E_SURF_W / 2); //l.y2 - blabla - coord not rel_coord
		elem->rel_coord.y = event.button.y - (E_SURF_H / 2);
	}
	//elem->coord.x = elem->rel_coord.x;
	//elem->coord.y = elem->rel_coord.y;
}
