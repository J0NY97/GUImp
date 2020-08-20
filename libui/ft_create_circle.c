/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:06:09 by nneronin          #+#    #+#             */
/*   Updated: 2020/08/20 13:04:01 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static inline void circle_clice(SDL_Surface *surf, Uint32 color, t_circle c)
{
    set_pixel(surf, c.xc + c.x, c.yc + c.y, color);
    set_pixel(surf, c.xc - c.x, c.yc + c.y, color);
    set_pixel(surf, c.xc + c.x, c.yc - c.y, color);
    set_pixel(surf, c.xc - c.x, c.yc - c.y, color);
    set_pixel(surf, c.xc + c.y, c.yc + c.x, color);
    set_pixel(surf, c.xc - c.y, c.yc + c.x, color);
    set_pixel(surf, c.xc + c.y, c.yc - c.x, color);
    set_pixel(surf, c.xc - c.y, c.yc - c.x, color);
}

void	ft_create_circle(SDL_Surface *surf, Uint32 color, t_circle c)
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
