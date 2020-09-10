/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 14:54:43 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/23 15:06:13 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_create_square(SDL_Surface *surface, Uint32 color, t_shapes l)
{
	int sx;
	int sy;

	sx = l.x1 - l.size;
	while (sx < l.x1 + l.size)
	{
		sy = l.y1 - l.size;
		while (sy < l.y1 + l.size)
		{
			if (sx >= 0 && sy >= 0 && sx <= surface->w && sy <= surface->h)
				set_pixel(surface, sx, sy, color);
			sy++;
		}
		sx++;
	}
}
