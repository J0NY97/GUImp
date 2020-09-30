/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 14:09:34 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/16 16:48:49 by jsalmi           ###   ########.fr       */
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
	float		aspect;
	SDL_Surface *surf;
	
	if (surface->h > surface->w)
	{
		aspect = (float)h / (float)surface->h;
		surf = ft_create_rgba_surface(surface->w * aspect, h);
	}
	else
	{
		aspect = (float)w / (float)surface->w;
		surf = ft_create_rgba_surface(w, surface->h * aspect);
	}
	SDL_BlitScaled(surface, NULL, surf, NULL);
	return (surf);
}
