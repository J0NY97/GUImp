/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:13:19 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/16 12:42:12 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

SDL_Surface 	*ft_create_rgba_surface(int w, int h)
{
	return (SDL_CreateRGBSurface(0, w, h, 32,
				0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000));
}

SDL_Rect		ft_sdl_rect(int x, int y, int w, int h)
{
	SDL_Rect rect;

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	return (rect);
}
