/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 14:09:34 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/12 18:11:37 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

SDL_Surface	*ft_scale_surface(SDL_Surface *surface, int w, int h)
{
	SDL_Surface *surf;

	surf = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
	SDL_BlitScaled(surface, NULL, surf, NULL);
	return (surf);
}

SDL_Surface	*ft_scale_surface_aspect(SDL_Surface *surface, int w, int h)
{
	SDL_Surface *surf;
	float aspect;
	
	if (surface->h > surface->w)
	{
		aspect = (float)h / (float)surface->h;
		surf = SDL_CreateRGBSurface(0, surface->w * aspect, h, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	}
	else
	{
		aspect = (float)w / (float)surface->w;
		surf = SDL_CreateRGBSurface(0, w, surface->h * aspect, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	}
	SDL_BlitScaled(surface, NULL, surf, NULL);
	return (surf);
}
