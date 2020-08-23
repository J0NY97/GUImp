/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:06:09 by nneronin          #+#    #+#             */
/*   Updated: 2020/08/23 14:17:52 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static inline void	boundaries(t_shapes *l, int w, int h)
{
	if (l->x1 >= w || l->x1 < 0)
		l->x1 = l->x1 < 0 ? 1 : w - 1;
	if (l->y1 >= h || l->y1 < 0)
		l->y1 = l->y1 < 0 ? 1 : h - 1;
	if (l->x2 >= w || l->x2 < 0)
		l->x2 = l->x2 < 0 ? 1 : w - 1;
	if (l->y2 >= h || l->y2 < 0)
		l->y2 = l->y2 < 0 ? 1 : h - 1;
}

static inline void full_or_empty(SDL_Surface *surf, Uint32 color, t_shapes l, int i)
{
	if (i == 1)
		ft_create_line(surf, color, l);
	else
	{
		set_pixel(surf, l.x1, l.y1, color);
		set_pixel(surf, l.x2, l.y2, color);
	}
}

static inline void full_circle(SDL_Surface *surf, Uint32 color, t_shapes c, int i)
{
	t_shapes l;

	l.size = 1;
	l.x1 = c.x2 + c.x;
	l.y1 = c.y2 - c.y;
	l.x2 = c.x2 - c.x;
	l.y2 = c.y2 - c.y;
	boundaries(&l, surf->w, surf->h);
    full_or_empty(surf, color, l, i);
	l.x1 = c.x2 + c.y;
	l.y1 = c.y2 - c.x;
	l.x2 = c.x2 - c.y;
	l.y2 = c.y2 - c.x;
	boundaries(&l, surf->w, surf->h);
    full_or_empty(surf, color, l, i);
	l.x1 = c.x2 + c.y;
	l.y1 = c.y2 + c.x;
	l.x2 = c.x2 - c.y;
	l.y2 = c.y2 + c.x;
	boundaries(&l, surf->w, surf->h);
    full_or_empty(surf, color, l, i);
	l.x1 = c.x2 + c.x;
	l.y1 = c.y2 + c.y;
	l.x2 = c.x2 - c.x;
	l.y2 = c.y2 + c.y;
	boundaries(&l, surf->w, surf->h);
    full_or_empty(surf, color, l, i);

}

void	ft_create_circle(SDL_Surface *surf, Uint32 color, t_shapes c, int i)
{
    int d;

    c.x = 0;
	c.y = c.size;
   	d = 3 - 2 * c.size;
    full_circle(surf, color, c, i);
    while (c.y >= c.x)
    {
        c.x++;
        if (d > 0)
        {
            c.y--;
            d = d + 4 * (c.x - c.y) + 10;
        }
        else
            d = d + 4 * c.x + 6;
    	full_circle(surf, color, c, i);
    }
}
