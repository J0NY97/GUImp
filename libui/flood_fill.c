/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 12:56:35 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/16 16:00:16 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	flood_fill(SDL_Surface *surface, Uint32 targetColor, Uint32 replaceColor, int x, int y)
{
	t_list	*pix;
	t_xywh *content;
	t_xywh coord;
	int iter = 1;
	int ix;
	int iy;
	int	spanAbove;
	int spanBelow;

	if (targetColor == replaceColor)
		return;
	coord = ui_init_coords(x, y, 0, 0);
	push_list(&pix, &coord, sizeof(t_coords));
	while (iter != 0 && (content = pop_list(&pix)) != NULL)
	{
		iter--;
		ix = ((t_xywh *)content)->x;
		iy = ((t_xywh *)content)->y;
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
				coord = ui_init_coords(ix, iy - 1, 0, 0);
				push_list(&pix, &coord, sizeof(t_xywh));
				iter++;
	            spanAbove = 1;
	        }
			else if (spanAbove == 1 && iy > 0 && get_color(surface, ix, iy - 1) != targetColor)
				spanAbove = 0;
			if (spanBelow == 0 && iy < surface->h - 1 && get_color(surface, ix, iy + 1) == targetColor)
			{
				coord = ui_init_coords(ix, iy + 1, 0, 0);
				push_list(&pix, &coord, sizeof(t_xywh));
				iter++;
	            spanBelow = 1;
	        }
	        else if (spanBelow == 1 && iy < surface->h - 1 && get_color(surface, ix, iy + 1) != targetColor)
	            spanBelow = 0;
	        ix++;
	    }
	}
}
