/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_surface.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 13:50:54 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/16 16:54:22 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_update_background(SDL_Surface *surface, Uint32 bg_color)
{
	int x;
	int y;

	y = -1;
	while (++y < surface->h)
	{
		x = -1;
		while (++x < surface->w)
			set_pixel(surface, x, y, bg_color);
	}
}
