/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 14:54:43 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/10 15:53:37 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_create_square(SDL_Surface *surface, Uint32 color, t_shapes l)
{
	int sx;
	int sy;

	sx = l.x1;
	while (sx < l.x2)
	{
		sy = l.y1;
		while (sy < l.y2)
		{
			set_pixel(surface, ft_clamp(sx, 0, surface->w - 1), ft_clamp(sy, 0, surface->h - 1), color);
			sy++;
		}
		sx++;
	}
}
