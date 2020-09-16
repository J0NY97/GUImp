/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:06:09 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/16 14:08:24 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static inline void	boundaries(t_shapes *l, int w, int h)
{
	if (l->x2 >= w || l->x2 < 0)
		l->x2 = l->x2 < 0 ? 0 : w - 1;
	if (l->y2 >= h || l->y2 < 0)
		l->y2 = l->y2 < 0 ? 0 : h - 1;
	if (l->x1 >= w || l->x1 < 0)
		l->x1 = l->x1 < 0 ? 0 : w - 1;
	if (l->y1 >= h || l->y1 < 0)
		l->y1 = l->y1 < 0 ? 0 : h - 1;
}

static inline void full_or_empty(SDL_Surface *surf, Uint32 color, t_shapes l)
{
	if (l.fill == 1)
		ft_create_line(surf, color, l);
	else
	{
//		set_blended_pixel(surf, l.x2, l.y2, color);
//		set_blended_pixel(surf, l.x1, l.y1, color);
		set_pixel(surf, l.x2, l.y2, color);
		set_pixel(surf, l.x1, l.y1, color);
	}
}

static inline void full_circle(SDL_Surface *surf, t_shapes c, int x, int y)
{
	t_shapes l;

	l.size = 1;
	l.fill = c.fill;
	l.x2 = c.x1 + x;
	l.y2 = c.y1 - y;
	l.x1 = c.x1 - x;
	l.y1 = c.y1 - y;
	boundaries(&l, surf->w, surf->h);
    full_or_empty(surf, c.color, l);
	l.x2 = c.x1 + y;
	l.y2 = c.y1 - x;
	l.x1 = c.x1 - y;
	l.y1 = c.y1 - x;
	boundaries(&l, surf->w, surf->h);
    full_or_empty(surf, c.color, l);
	l.x2 = c.x1 + y;
	l.y2 = c.y1 + x;
	l.x1 = c.x1 - y;
	l.y1 = c.y1 + x;
	boundaries(&l, surf->w, surf->h);
    full_or_empty(surf, c.color, l);
	l.x2 = c.x1 + x;
	l.y2 = c.y1 + y;
	l.x1 = c.x1 - x;
	l.y1 = c.y1 + y;
	boundaries(&l, surf->w, surf->h);
    full_or_empty(surf, c.color, l);
}

void	ft_create_circle(SDL_Surface *surf, Uint32 color, t_shapes c)
{
	int x;
	int y;
    int dist;

    x = 0;
	y = c.size;
	c.color = color;
   	dist = 3 - 2 * c.size;
    full_circle(surf, c, x, y);
    while (y >= x)
    {
        x++;
        if (dist >= 0)
        {
            y--;
            dist = dist + 4 * (x - y) + 10;
        }
        else
            dist = dist + 4 * x + 6;
    	full_circle(surf, c, x, y);
    }
}
