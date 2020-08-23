/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 12:56:35 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/23 14:28:54 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

Uint32  get_color(SDL_Surface *surface, int x, int y)
{
    Uint32 *pixels;

	pixels = surface->pixels;
	return (pixels[y * surface->w + x]);
}

void	fake_flood_fill(SDL_Surface *surface, Uint32 targetColor, Uint32 replaceColor, int x, int y, int dir)
{
	Uint32 node;

	if (x < surface->w && y < surface->h && x >= 0 && y >= 0)
	{
		node = get_color(surface, x, y);
		if (targetColor == replaceColor)
			return;
		if (node != targetColor)
			return ;
		else
		{
			set_pixel(surface, x, y, replaceColor);
			if (dir == 1)
			{
				fake_flood_fill(surface, targetColor, replaceColor, x, y + 1, dir);
				fake_flood_fill(surface, targetColor, replaceColor, x + 1, y, dir);
			}
			if (dir == 2)
			{		
				fake_flood_fill(surface, targetColor, replaceColor, x, y - 1, dir);
				fake_flood_fill(surface, targetColor, replaceColor, x - 1, y, dir);
			}
			if (dir == 3)
			{
				fake_flood_fill(surface, targetColor, replaceColor, x + 1, y, dir);
				fake_flood_fill(surface, targetColor, replaceColor, x, y - 1, dir);	
			}
			if (dir == 4)
			{
				fake_flood_fill(surface, targetColor, replaceColor, x - 1, y, dir);
				fake_flood_fill(surface, targetColor, replaceColor, x, y + 1, dir);
			}
		}	
	}
	return ;
}

void	flood_fill(SDL_Surface *surface, Uint32 targetColor, Uint32 replaceColor, int x, int y)
{
	fake_flood_fill(surface, targetColor, replaceColor, x, y, 1);
	set_pixel(surface, x, y, targetColor);
	fake_flood_fill(surface, targetColor, replaceColor, x, y, 2);
	set_pixel(surface, x, y, targetColor);
	fake_flood_fill(surface, targetColor, replaceColor, x + 1, y - 1, 3);
	set_pixel(surface, x, y, targetColor);
	fake_flood_fill(surface, targetColor, replaceColor, x - 1, y + 1, 4);
	set_pixel(surface, x, y, replaceColor);
}
