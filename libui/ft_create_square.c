/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 14:54:43 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/12 14:03:26 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_create_square(SDL_Surface *surface, Uint32 color, t_shapes l)
{
	int sx;
	int sy;
	int ex;
	int ey;

	sx = ft_min(l.x1, l.x2);
	ex = ft_max(l.x1, l.x2);
	while (sx < ex)
	{
		sy = ft_min(l.y1, l.y2);
		ey = ft_max(l.y1, l.y2);
		while (sy < ey)
		{
			set_pixel(surface, ft_clamp(sx, 0, surface->w - 1), ft_clamp(sy, 0, surface->h - 1), color);
			sy++;
		}
		sx++;
	}
}
