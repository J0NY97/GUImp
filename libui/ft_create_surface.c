/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_surface.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:59:34 by jsalmi            #+#    #+#             */
/*   Updated: 2020/08/16 16:28:22 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int		ft_create_surface(t_surface_info info)
{
	t_surface *new_surface;
	if (!(new_surface = (t_surface *)malloc(sizeof(t_surface))))
		ft_putstr("[create_surface] Couldnt malloc new surface.\n");
	new_surface->surface = SDL_CreateRGBSurface(0, info.w, info.h, 32, 0, 0, 0, 0);
	new_surface->x = info.x;
	new_surface->y = info.y;
	info.win->surfaces[++info.win->surface_amount] = new_surface;
	// color whole surface white
	int x;
	int y;
	y = -1;
	while (++y < info.h)
	{
		x = -1;
		while (++x < info.w)
		{
			set_pixel(new_surface->surface, x, y, 0xffffff);
		}
	}
	return (1);
}
