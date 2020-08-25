/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 12:56:35 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/25 15:14:56 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

Uint32  get_color(SDL_Surface *surface, int x, int y)
{
    Uint32 *pixels;

	pixels = surface->pixels;
	return (pixels[y * surface->w + x]);
}

void	fake_flood_fill(SDL_Surface *surface, Uint32 targetColor, Uint32 replaceColor, int x, int y)
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
			fake_flood_fill(surface, targetColor, replaceColor, x, y + 1);
			fake_flood_fill(surface, targetColor, replaceColor, x + 1, y);
			fake_flood_fill(surface, targetColor, replaceColor, x, y - 1);
			fake_flood_fill(surface, targetColor, replaceColor, x - 1, y);
		}
	}
	return ;
}

t_coords	set_coords(int x, int y)
{
	t_coords coord;

	coord.x = x;
	coord.y = y;
	return (coord);
}

void	flood_fill(SDL_Surface *surface, Uint32 targetColor, Uint32 replaceColor, int x, int y)
{
	t_list	*pix;
	t_coords *content;
	t_coords coord;
	int iter = 1;
	int ix;
	int iy;
	int	spanAbove;
	int spanBelow;

	if (targetColor == replaceColor)
		return;
	coord = set_coords(x, y);
	push_list(&pix, &coord, sizeof(t_coords));
	while (iter != 0 && (content = pop_list(&pix)) != NULL)
	{
		iter--;
		ix = ((t_coords *)content)->x;
		iy = ((t_coords *)content)->y;
		free(content);
		while (ix > 0 && get_color(surface, ix - 1, iy) == targetColor)
			ix--;
		spanAbove = 0;
		spanBelow = 0;
		while(ix < surface->w && get_color(surface, ix, iy) == targetColor)
		{
			set_pixel(surface, ix, iy, replaceColor);
			if(spanAbove == 0 && iy > 0 && get_color(surface, ix, iy - 1) == targetColor)
			{
				coord = set_coords(ix, iy - 1);
				push_list(&pix, &coord, sizeof(t_coords));
				iter++;
	            spanAbove = 1;
	        }
			else if (spanAbove == 1 && iy > 0 && get_color(surface, ix, iy - 1) != targetColor)
				spanAbove = 0;
			if (spanBelow == 0 && iy < surface->h - 1 && get_color(surface, ix, iy + 1) == targetColor)
			{
				coord = set_coords(ix, iy + 1);
				push_list(&pix, &coord, sizeof(t_coords));
				iter++;
	            spanBelow = 1;
	        }
	        else if (spanBelow == 1 && iy < surface->h - 1 && get_color(surface, ix, iy + 1) != targetColor)
	            spanBelow = 0;
	        ix++;
	    }
	}
}
