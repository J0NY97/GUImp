/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_and_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 14:39:16 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/09 17:32:37 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

#define E_SURF_W elem->surface->w
#define E_SURF_H elem->surface->h

void	zoom_and_move(t_element *elem, SDL_Event event)
{
	SDL_Surface *surf;
	int a = (float)(E_SURF_W / 100);
	int b = (float)(E_SURF_H / 100);

	if (event.type == SDL_MOUSEWHEEL && event.wheel.y != 0)
	{
		a = event.wheel.y > 0 ? -a : a;
		b = event.wheel.y > 0 ? -b : b;
		surf = SDL_CreateRGBSurface(0, E_SURF_W - a, E_SURF_H - b, 32, 0, 0, 0, 0);
		//elem->rel_coord.x += event.wheel.y < 0 ? -3 : 3;
		//elem->rel_coord.y += event.wheel.y < 0 ? -3 : 3;
		SDL_FreeSurface(elem->surface);
		elem->surface = surf;
	}
	else
	{
		elem->rel_coord.x = event.button.x - (E_SURF_W / 2); //l.y2 - blabla - coord not rel_coord
		elem->rel_coord.y = event.button.y - (E_SURF_H / 2);
	}
}
