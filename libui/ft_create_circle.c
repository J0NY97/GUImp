/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:06:09 by nneronin          #+#    #+#             */
/*   Updated: 2020/08/19 18:04:12 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static inline void circle_clice(SDL_Surface *surf, Uint32 color, t_circle c)
{
	t_line l;

	l.x1 = c.xc + c.x;
	l.y1 = c.yc + c.y;
	l.x2 = c.xc - c.x;
	l.y2 = c.yc + c.y;
	ft_create_line(surf, color, &l);
	l.x1 = c.xc + c.x;
	l.y1 = c.yc - c.y;
	l.x2 = c.xc - c.x;
	l.y2 = c.yc - c.y;
	ft_create_line(surf, color, &l);
	l.x1 = c.xc + c.y;
	l.y1 = c.yc + c.x;
	l.x2 = c.xc - c.y;
	l.y2 = c.yc + c.x;
	ft_create_line(surf, color, &l);
	l.x1 = c.xc + c.y;
	l.y1 = c.yc - c.x;
	l.x2 = c.xc - c.y;
	l.y2 = c.yc - c.x;
	ft_create_line(surf, color, &l);
	return ;
    set_pixel(surf, c.xc + c.x, c.yc + c.y, color);
    set_pixel(surf, c.xc - c.x, c.yc + c.y, color);
    set_pixel(surf, c.xc + c.x, c.yc - c.y, color);
    set_pixel(surf, c.xc - c.x, c.yc - c.y, color);
    set_pixel(surf, c.xc + c.y, c.yc + c.x, color);
    set_pixel(surf, c.xc - c.y, c.yc + c.x, color);
    set_pixel(surf, c.xc + c.y, c.yc - c.x, color);
    set_pixel(surf, c.xc - c.y, c.yc - c.x, color);
}

void	draw_circle(SDL_Surface *surf, Uint32 color, t_circle c)
{
    int d;

    c.x = 0;
	c.y = c.r;
   	d = 3 - 2 * c.r;
    circle_clice(surf, color, c);
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
    	circle_clice(surf, color, c);
    }
}
